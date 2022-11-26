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

void	ft_printing(char *s, t_philo *ph)
{
	pthread_mutex_lock(ph->mutex);
	printf("%s", s);
	pthread_mutex_unlock(ph->mutex);
}
