# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 17:46:03 by skhaliff          #+#    #+#              #
#    Updated: 2022/11/25 22:01:43 by skhaliff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS_PHILO = philo.c ft_atoi.c ft_isdigit.c ft_error.c ft_print.c
CC		= cc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror -pthread

all: $(NAME)

$(NAME): $(SRCS_PHILO)
		$(CC) $(CFLAGS) $(SRCS_PHILO) -o $(NAME)

clean:
		$(RM) $(NAME)

fclean:	clean

re:		fclean all