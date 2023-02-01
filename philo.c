/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:58:27 by skhaliff          #+#    #+#             */
/*   Updated: 2022/11/25 22:11:04 by skhaliff         ###   ########.fr       */
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
			ft_error("ERROR");
		i++;
	}
	return (1);
}

void    *routine(void *arg)
{
    t_philo	*philo;

	philo = (t_philo *) arg;
    while (1)
    {
        eat(philo);
        sleepng(philo);
        ft_printing("is Thinking", philo);
    }
}


void    create_threads(t_philo *philo, t_data *data)
{
    int i;

    i = 0;
    while (i < data->nmbr_philo)
    {
        pthread_create(&philo[i].ph, NULL, &routine, &philo[i]);
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
				return(0);
			philo = init_philo(philo, data);
			if (!philo)
				return (0);
			mutex(philo, data);
			create_threads(philo, data);
			//supervisor(philo, data);
			if_death(philo);
		}
		else
			ft_error("ERrOr");
	}
	else
		ft_error("ARGUMENT!!!");
}
