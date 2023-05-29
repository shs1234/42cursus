# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 22:35:13 by hoseoson          #+#    #+#              #
#    Updated: 2023/05/28 17:58:17 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
NAME_B		=	checker
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rcs
RM			=	rm -rf
HEADER		=	push_swap.h
HEADER_B	=	push_swap_bonus.h

SRCS	=	main.c input_valid.c ft_sorting.c utils1.c utils2.c utils3.c \
			instruction1.c instruction2.c instruction3.c atob.c btoa.c \
			ft_atoi.c ft_lstadd_back.c ft_split.c
SRCS_B	=	bonus/checker_bonus.c bonus/input_valid_bonus.c bonus/get_next_line_bonus.c \
			bonus/get_next_line_utils_bonus.c bonus/ft_split_bonus.c \
			bonus/instruction1_bonus.c bonus/instruction2_bonus.c bonus/instruction3_bonus.c \
			bonus/utils1_bonus.c bonus/atob_bonus.c bonus/btoa_bonus.c bonus/ft_atoi_bonus.c \
			bonus/utils2_bonus.c bonus/utils3_bonus.c

OBJS	=	$(SRCS:.c=.o)
OBJS_B	=	$(SRCS_B:.c=.o)

ifdef BONUS
	SWITCH_NAME = $(NAME_B)
	SWITCH_OBJS = $(OBJS_B)
	SWITCH_HEADER = $(HEADER_B)
else
	SWITCH_NAME = $(NAME)
	SWITCH_OBJS = $(OBJS)
	SWITCH_HEADER = $(HEADER)
endif

all : $(SWITCH_NAME)

bonus :
	$(MAKE) BONUS=1 all

$(SWITCH_NAME) : $(SWITCH_OBJS)
	$(CC) -o $@ $^

%.o : %.c $(SWITCH_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(RM) $(NAME) $(NAME_B)

re : fclean all

.PHONY: all clean fclean re bonus