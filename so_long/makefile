# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 00:56:33 by hoseoson          #+#    #+#              #
#    Updated: 2023/06/08 06:12:15 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf
FRAMEWORK	= -framework OpenGL -framework AppKit

SRCS        = main.c utils.c move.c make_map.c valid_map.c
OBJS        = $(SRCS:.c=.o)
HEADER      = so_long.h

SRCS_B      = bonus/main_bonus.c bonus/enemy_bonus.c bonus/patrol_bonus.c \
				bonus/make_map_bonus.c bonus/valid_map_bonus.c bonus/utils_bonus.c \
				bonus/move_bonus.c bonus/img_init_bonus.c bonus/rendering_bonus.c				
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