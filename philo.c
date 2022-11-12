/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:58:27 by skhaliff          #+#    #+#             */
/*   Updated: 2022/11/04 17:49:33 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void)
{
	printf("here we go again\n");
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(ft_atoi(argv[1]) * sizeof(t_philo));
	while (i < (argc - 1))
	{
		pthread_create(&philo[i], NULL, &routine, NULL);
		i++;
	}
	//pthread_join(t1, NULL);
}
