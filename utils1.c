/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:00:41 by skhaliff          #+#    #+#             */
/*   Updated: 2022/11/25 22:16:29 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	gette_time(void)
{
	long	ss;
	t_time Ti;
	gettimeofday(&Ti , NULL);
	ss = (Ti.tv_sec * 1000) + (Ti.tv_usec / 1000);
	return(ss);
}

void	ft_sleep(unsigned long us)
{
	unsigned long	begin;

	begin = gette_time();
	while (gette_time() - begin < us)
		;
}

void	mutex(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->printing, NULL);
	pthread_mutex_init(&philo->data->check_eat, NULL);
    pthread_mutex_init(&philo->data->eat, NULL);
	while(i < data->nmbr_philo)
		pthread_mutex_init(&philo->forks[i++], NULL);
}

void	ft_printing(char *s, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->printing);
	printf("%ld ms Philo NUM %d  %s\n", gette_time() - philo->start, philo->index, s);
	pthread_mutex_unlock(&philo->data->printing);
}