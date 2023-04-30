# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 00:56:33 by hoseoson          #+#    #+#              #
#    Updated: 2023/04/30 07:51:29 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS		=	-g
RM			=	rm -rf

SRCS		=	main.c pipex.c utils.c
OBJS		=	$(SRCS:.c=.o)
HEADER		=	pipex.h

SRCS_B		=	main_bonus.c pipex_bonus.c utils_bonus.c
OBJS_B		=	$(SRCS_B:.c=.o)
HEADER_B	=	pipex_bonus.h


ifdef BONUS
	SWITCH_OBJS = $(OBJS_B)
	SWITCH_HEADER = $(HEADER_B)
else
	SWITCH_OBJS = $(OBJS)
	SWITCH_HEADER = $(HEADER)
endif

all : $(NAME)
	sleep 1

bonus :
	$(MAKE) BONUS=1 all

$(NAME) : $(SWITCH_OBJS)
	$(MAKE) -C libft
	$(MAKE) -C ft_printf
	$(CC) -o $@ $^ ./ft_printf/libftprintf.a ./libft/libft.a -I./libft/ -I./ft_printf/

%.o : %.c $(SWITCH_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(MAKE) -C libft $@
	$(MAKE) -C ft_printf $@
	$(RM) $(OBJS) $(OBJS_B) 

fclean : clean
	$(MAKE) -C libft $@
	$(MAKE) -C ft_printf $@
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus