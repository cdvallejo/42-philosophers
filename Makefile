# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvallejo <cvallejo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 09:58:38 by cvallejo          #+#    #+#              #
#    Updated: 2024/05/01 16:43:25 by cvallejo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = philo_main.c philo_utils.c philo_init.c
CC = gcc -pthread
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJS = ${SRCS:.c=.o}

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:
		$(RM) $(OBJS) $(NAME)

re:				fclean all

.PHONY:	all clean fclean re