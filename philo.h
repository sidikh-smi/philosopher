/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:43:35 by skhaliff          #+#    #+#             */
/*   Updated: 2023/02/03 10:09:31 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

typedef struct timeval t_time;

typedef struct s_data{
	int				nmbr_philo;
	int				time_eat;
	int				time_sleep;
	int				time_die;
	int				nmbr_time_eat;
	pthread_mutex_t	printing;
	pthread_mutex_t	eat;
	pthread_mutex_t	check_eat;
	long			start;
}	t_data;

typedef struct s_philo{
	pthread_t		ph;
	int				index;
	long			last_eat;
	t_data			*data;
	int				nmbr_eat;
	pthread_mutex_t	*forks;
	int				eat;
	int				i;
}	t_philo;

int		ft_atoi(const char *str);
void	ft_printing(char *s, t_philo *philo);
int		check_arg(int argc, char **argv);
void	eat(t_philo *philo);
void	sleepng(t_philo *philo);
void	create_threads(t_philo *philo, t_data *data);
t_data	*init_data(char **argv);
t_philo	*init_philo(t_data *data);
long	gette_time(void);
int		mutex(t_philo *philo, t_data *data);
void	death(t_philo *philo);
void	ft_sleep(unsigned int time);
long	time_now(void);

#endif