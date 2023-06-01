# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 00:56:33 by hoseoson          #+#    #+#              #
#    Updated: 2023/05/30 04:08:33 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = philo
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf

SRCS        = main.c ft_atoi.c utils.c philosophers.c status.c
OBJS        = $(SRCS:.c=.o)
HEADER      = philo.h

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re