/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:58:27 by skhaliff          #+#    #+#             */
/*   Updated: 2023/02/03 12:04:13 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) == 0)
			return (-1);
		i++;
	}
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (1)
	{
		eat(philo);
		sleepng(philo);
		ft_printing("is Thinking", philo);
		pthread_mutex_lock(&philo->data->eat);
		philo->eat = 0;
		pthread_mutex_unlock(&philo->data->eat);
	}
}

void	create_threads(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	data->start = time_now();
	pthread_mutex_init(&data->printing, NULL);
	while (i < data->nmbr_philo)
	{
		philo[i].last_eat = time_now();
		if (pthread_create(&philo[i].ph, NULL, &routine, &philo[i]))
			return ;
		usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;
	int		i;

	i = 0;
	philo = NULL;
	data = NULL;
	if (argc == 5 || argc == 6)
	{
		if (check_arg(argc, argv))
		{
			data = init_data(argv);
			if (!data)
				return (-1);
			philo = init_philo(data);
			if (!philo)
				return (-1);
			create_threads(philo, data);
			death(philo, data);
		}
		else
			return (-1);
	}
	else
		return (-1);
}
