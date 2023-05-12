# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 00:56:33 by hoseoson          #+#    #+#              #
#    Updated: 2023/05/13 08:50:18 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long
# CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf

SRCS        = main.c get_next_line.c get_next_line_utils.c map.c utils.c move.c
OBJS        = $(SRCS:.c=.o)
HEADER      = so_long.h
FRAMEWORK	= -lXext -lX11

all : $(NAME)

$(NAME) : $(OBJS)
	# $(MAKE) -C libft
	# $(MAKE) -C minilibx-linux
	$(CC) -o $@ $^ ./libft/libft.a ./minilibx-linux/libmlx.a $(FRAMEWORK)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	# $(MAKE) -C libft $@
	# $(MAKE) -C minilibx-linux $@
	$(RM) $(OBJS)

fclean : clean
	# $(MAKE) -C libft $@
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
