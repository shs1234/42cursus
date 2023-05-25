# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 00:56:33 by hoseoson          #+#    #+#              #
#    Updated: 2023/05/26 02:36:24 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf
FRAMEWORK	= -framework OpenGL -framework AppKit

SRCS        = main.c get_next_line.c get_next_line_utils.c map.c utils.c move.c utils2.c
OBJS        = $(SRCS:.c=.o)
HEADER      = so_long.h

SRCS_B      = bonus/main_bonus.c bonus/utils2_bonus.c \
				bonus/map_bonus.c bonus/utils_bonus.c bonus/move_bonus.c \
				bonus/img_init_bonus.c bonus/rendering_bonus.c \
				bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c
OBJS_B      = $(SRCS_B:.c=.o)
HEADER_B    = bonus/so_long_bonus.h

ifdef BONUS
	SWITCH_OBJS = $(OBJS_B)
	SWITCH_HEADER = $(HEADER_B)
else
	SWITCH_OBJS = $(OBJS)
	SWITCH_HEADER = $(HEADER)
endif

all : $(NAME)

bonus :
	$(MAKE) BONUS=1 all

$(NAME) : $(SWITCH_OBJS)
	$(MAKE) -C libft
	$(MAKE) -C minilibx_mac
	mv ./minilibx_mac/libmlx.dylib ./
	$(CC) $(CFLAGS) -o $@ $^ ./libft/libft.a libmlx.dylib $(FRAMEWORK)

%.o : %.c $(SWITCH_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(MAKE) -C libft $@
	$(MAKE) -C minilibx_mac $@
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(MAKE) -C libft $@
	$(RM) libmlx.dylib
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus