/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:51:29 by skhaliff          #+#    #+#             */
/*   Updated: 2022/11/25 22:03:18 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

long	convert_num(const char *s, int isneg)
{
	int					i;
	long long			nbr;

	i = 0;
	nbr = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr = (nbr * 10) + (s[i++] - '0');
		if (nbr > 9223372036854775807)
		{
			if (isneg == 0)
				return (-1);
			if (isneg == 1)
				return (0);
		}
	}
	return (nbr);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	nbr;
	int		isneg;

	i = 0;
	nbr = 0;
	isneg = 0;
	if (str[0] == '\0')
		ft_error("ERROR\n");
	while (str[i] != '\0' && (str[i] == ' '
			|| str[i] == '\t' || str[i] == '\n'))
		i++;
	if (str[i] <= 48 && str[i] >= 57)
		ft_error("ERROR\n");
	//printf("%c\n", str[i]);
	if (str[i] == '-')
	{
		isneg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	nbr = convert_num(str + i, isneg);
	if (isneg == 1)
		nbr = -nbr;
	if (nbr > INT_MAX || nbr < INT_MIN)
		ft_error("ERROR\n");
	return (nbr);
}
