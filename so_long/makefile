# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 00:56:33 by hoseoson          #+#    #+#              #
#    Updated: 2023/05/09 19:59:06 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf

SRCS        = main.c
OBJS        = $(SRCS:.c=.o)
HEADER      = so_long.h

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C ft_printf
	$(CC) -o $@ $^ ./ft_printf/libftprintf.a ./libft/libft.a -I./libft/ -I./ft_printf/

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(MAKE) -C libft $@
	$(MAKE) -C ft_printf $@
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C libft $@
	$(MAKE) -C ft_printf $@
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
