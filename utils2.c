/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:23:31 by skhaliff          #+#    #+#             */
/*   Updated: 2023/02/03 11:55:56 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->i]);
	ft_printing("has taken a fork", philo);
	pthread_mutex_lock(&philo->forks[(philo->i + 1) 
		% philo->data->nmbr_philo]);
	ft_printing("has taken a fork", philo);
	pthread_mutex_lock(&philo->data->check_eat);
	ft_printing("is eating", philo);
	philo->last_eat = time_now();
	philo->eat = 1;
	philo->nmbr_eat++;
	pthread_mutex_unlock(&philo->data->check_eat);
	ft_sleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(&philo->forks[philo->i]);
	pthread_mutex_unlock(&philo->forks[(philo->i + 1)
		% philo->data->nmbr_philo]);
}

void	sleepng(t_philo *philo)
{
	ft_printing("is sleeping", philo);
	ft_sleep(philo->data->time_sleep * 1000);
}
