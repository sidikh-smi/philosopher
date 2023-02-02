/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:00:41 by skhaliff          #+#    #+#             */
/*   Updated: 2023/02/02 23:54:24 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_now(void)
{
	long	ss;
	t_time	ti;

	gettimeofday(&ti, NULL);
	ss = (ti.tv_sec * 1000) + (ti.tv_usec / 1000);
	return (ss);
}

long	gette_time(void)
{
	long	ss;
	t_time	ti;

	gettimeofday(&ti, NULL);
	ss = (ti.tv_sec * 1000000) + (ti.tv_usec);
	return (ss);
}

void	ft_sleep(unsigned long time)
{
	unsigned long	begin;

	begin = gette_time();
	usleep(time - 20000);
	while (gette_time() - begin < time)
		;
}

int	mutex(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	printf("hellooooooooo\n");
	philo->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->nmbr_philo);
	if (!philo->forks)
		ft_error("error");
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
	printf("%ld ms Philo NUM %d  %s\n", time_now() - philo->start, 
		philo->index, s);
	pthread_mutex_unlock(&philo->data->printing);
}
