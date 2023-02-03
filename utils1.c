/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:00:41 by skhaliff          #+#    #+#             */
/*   Updated: 2023/02/03 11:41:50 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_now(void)
{
	t_time	ti;

	gettimeofday(&ti, NULL);
	return ((ti.tv_sec * 1000) + (ti.tv_usec / 1000));
}

long	gette_time(void)
{
	long	ss;
	t_time	ti;

	gettimeofday(&ti, NULL);
	ss = (ti.tv_sec * 1000000) + (ti.tv_usec);
	return (ss);
}

void	ft_sleep(unsigned int time)
{
	long	begin;

	begin = gette_time();
	usleep(time - 20000);
	while (gette_time() - begin < time)
		;
}

int	mutex(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	philo->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->nmbr_philo);
	if (!philo->forks)
		return (-1);
	while (i < data->nmbr_philo)
	{
		if (pthread_mutex_init(&philo->forks[i], NULL))
			return (0);
		i++;
	}
	return (1);
}

void	ft_printing(char *s, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->printing);
	printf("%ld ms Philo NUM %d  %s\n", time_now() - philo->data->start, 
		philo->index, s);
	pthread_mutex_unlock(&philo->data->printing);
}
