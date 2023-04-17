# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 22:35:13 by hoseoson          #+#    #+#              #
#    Updated: 2023/04/17 21:49:31 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
NAME_B	=	checker
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rcs
RM		=	rm -rf
HEADER	=	push_swap.h

SRCS	=	main.c input_valid.c ft_sorting.c utils.c \
			instruction_1.c instruction_2.c instruction_3.c atob.c btoa.c \
			ft_atoi.c ft_lstadd_back.c ft_split.c

SRCS_B	=	checker.c input_valid.c get_next_line.c get_next_line_utils.c \
			ft_sorting.c instruction_1.c instruction_2.c instruction_3.c \
			utils.c atob.c btoa.c ft_atoi.c ft_lstadd_back.c ft_split.c

OBJS	=	$(SRCS:.c=.o)
OBJS_B	=	$(SRCS_B:.c=.o)

ifdef BONUS
	SWITCH_NAME = $(NAME_B)
	SWITCH_OBJS = $(OBJS_B)
else
	SWITCH_NAME = $(NAME)
	SWITCH_OBJS = $(OBJS)
endif

all : $(SWITCH_NAME)

bonus :
	$(MAKE) BONUS=1 all

$(SWITCH_NAME) : $(SWITCH_OBJS)
	$(CC) -o $@ $^

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(RM) $(NAME) $(NAME_B)

re : fclean all

.PHONY: all clean fclean re bonus