# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 00:56:33 by hoseoson          #+#    #+#              #
#    Updated: 2023/05/10 06:45:51 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long
# CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf

SRCS        = main.c
OBJS        = $(SRCS:.c=.o)
HEADER      = so_long.h
FRAMEWORK	= -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C minilibx
	mv ./minilibx/libmlx.dylib ./
	$(CC) -o $@ $^ ./libft/libft.a libmlx.dylib $(FRAMEWORK)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(MAKE) -C libft $@
	$(MAKE) -C minilibx $@
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C libft $@
	$(RM) libmlx.dylib
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
