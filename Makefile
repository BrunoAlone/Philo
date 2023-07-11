# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 09:00:51 by brolivei          #+#    #+#              #
#    Updated: 2023/07/03 15:20:26 by brolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Wextra -Werror -pthread -g -fsanitize=thread

PHILO = philo

SRCS_PHILO = main.c ft_check_args.c ft_make_them_alive.c ft_clean_mutex.c ft_routine.c\
				ft_send_msg.c ft_routine_pat.c ft_after_pick_forks.c ft_reduce_lines.c\
				utils/atoi.c utils/get_time.c utils/ft_is_digit.c

OBJS_PHILO = $(SRCS_PHILO:.c=.o)

all: $(PHILO)

$(PHILO):		$(OBJS_PHILO)

				$(CC) $(CCFLAGS) $(OBJS_PHILO) -o $(PHILO)

%.o: %.c
				$(CC) $(CCFLAGS) -c $< -o $@

clean:
				rm -rf $(OBJS_PHILO)

fclean: clean
				rm -rf $(PHILO)

re: fclean all
