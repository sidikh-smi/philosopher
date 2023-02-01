/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:26:04 by skhaliff          #+#    #+#             */
/*   Updated: 2022/11/12 17:29:37 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init_data(char **argv)
{
    t_data *s;

    s = malloc(sizeof(t_philo));
    s->nmbr_philo = ft_atoi(argv[1]);
    s->time_die = ft_atoi(argv[2]);
    s->time_eat = ft_atoi(argv[3]);
    s->time_sleep = ft_atoi(argv[4]);
    s->nmbr_time_eat = -1;
    if(argv[5])
        s->nmbr_time_eat = ft_atoi(argv[5]);
    return (s);
}

t_philo *init_philo(t_philo *philo, t_data *data)
{
    int             i;
    pthread_mutex_t *forks;

    forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->nmbr_philo);
    if (!forks)
        ft_error("error");
    philo = (t_philo *)malloc(sizeof(t_philo) * data->nmbr_philo);
    i = 0;
    while (i < data->nmbr_philo)
    {
        philo[i].index = i + 1;
        philo[i].nmbr_eat = 0;
        philo[i].eat = 0;
        philo[i].data = data;
        philo[i].start = gette_time();
        philo[i].forks = forks;
        philo[i].last_eat = gette_time();
        i++;
    }
    return (philo);
}