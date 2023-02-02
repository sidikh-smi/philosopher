# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 17:46:03 by skhaliff          #+#    #+#              #
#    Updated: 2023/02/02 22:36:08 by skhaliff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS_PHILO = philo.c ft_atoi.c ft_error.c utils1.c utils2.c init.c
CC		= cc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread

all: $(NAME)

$(NAME): $(SRCS_PHILO)
		$(CC) $(CFLAGS) $(SRCS_PHILO) -o $(NAME)

clean:
		$(RM) $(NAME)

fclean:	clean

re:		fclean all