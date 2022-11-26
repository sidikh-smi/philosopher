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

void	*routine(void *argv)
{
	t_philo	*s;

	s = (t_philo *)argv;
	// while (1)
	// {
		//eat(s);
		ft_printing("is sleeping\n", s);
		//printf("here we go again\n");
	//}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	int		i;
	//(void)argc;

	i = 0;
	philo = malloc(ft_atoi(argv[1]) * sizeof(t_philo));
	//printf("here\n");
	if (argc == 1)
		ft_error("ERROR\n");
	if (argc == 2 || argc == 3)
	{
		while (i < ft_atoi(argv[1]))
		{
			pthread_create(&(philo[i].philo), NULL, &routine, argv);
			pthread_join((philo[i].philo), NULL);
			usleep(1000000);
			i++;
		}
	}
	//printf("here\n");
}
