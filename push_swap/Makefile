# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 22:35:13 by hoseoson          #+#    #+#              #
#    Updated: 2023/04/08 23:53:09 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
# CFLAGS	=	-Wall -Wextra -Werror
CFLAGS	=	
AR		=	ar rcs
RM		=	rm -rf
HEADER	=	push_swap.h
LIBFT   =	make -C libft

SRCS	=	main.c input_valid.c ft_sorting.c utils.c \
			command_1.c command_2.c command_3.c 

OBJS	=	$(SRCS:.c=.o)

# 맆프티나 프린트 코드 변경해도 리링크 되는지 확인
all : $(NAME)

$(NAME) : $(OBJS)
	$(LIBFT) bonus
	$(CC) -o $@ $^ ./libft/libft.a

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(LIBFT) clean
	$(RM) $(OBJS)

fclean : clean
	$(LIBFT) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re