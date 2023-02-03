/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:55:04 by skhaliff          #+#    #+#             */
/*   Updated: 2023/02/03 12:07:39 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	finish_eat(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nmbr_philo)
	{
		if (philo[i].nmbr_eat < philo->data->nmbr_time_eat)
			return (0);
		i++;
	}
	return (1);
}

void	lock(pthread_mutex_t *check_eat, pthread_mutex_t *eat)
{
	pthread_mutex_lock(check_eat);
	pthread_mutex_lock(eat);
}

void	unlock(pthread_mutex_t *check_eat, pthread_mutex_t *eat)
{
	pthread_mutex_unlock(check_eat);
	pthread_mutex_unlock(eat);
}

void	death(t_philo *philo, t_data *data)
{
	int		i;

	while (1)
	{
		i = 0;
		while (i < philo->data->nmbr_philo)
		{
			lock(&philo[i].data->check_eat, &philo[i].data->eat);
			if (time_now() - philo[i].last_eat >= data->time_die
				&& !philo[i].eat)
			{
				pthread_mutex_lock(&philo[i].data->printing);
				printf("%ld ms Philo Number %d Died \n",
					(time_now() - philo->data->start), philo->index);
				return ;
			}
			unlock(&philo[i].data->check_eat, &philo[i].data->eat);
			i++;
		}
		pthread_mutex_lock(&philo->data->check_eat);
		if (data->nmbr_time_eat != -1 && finish_eat(philo))
			return ;
		pthread_mutex_unlock(&philo->data->check_eat);
	}
}
