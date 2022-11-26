/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:43:35 by skhaliff          #+#    #+#             */
/*   Updated: 2022/11/25 22:16:16 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_philo{
	pthread_t		philo;
	pthread_mutex_t	*mutex;
	int				eat;
	int				sleep;
	int				die;
}t_philo;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_error(char *s);
void	ft_printing(char *s, t_philo *ph);

#endif