# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 00:56:33 by hoseoson          #+#    #+#              #
#    Updated: 2023/04/25 07:56:55 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
HEADER	=	pipex.h

SRCS	=	main.c pipex.c utils.c
OBJS	=	$(SRCS:.c=.o)

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