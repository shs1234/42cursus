# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 00:56:33 by hoseoson          #+#    #+#              #
#    Updated: 2023/09/23 16:25:55 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cup3d
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf
FRAMEWORK	= -framework OpenGL -framework AppKit

SRC_DIR 	= 	srcs
OBJ_DIR 	= 	objs
SRCS 		= 	$(wildcard $(SRC_DIR)/*.c)
OBJS 		= 	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
HEADER      =   $(SRC_DIR)/cup3d.h

all : $(OBJ_DIR) $(NAME)

$(OBJ_DIR) :
	mkdir -p $@

$(NAME) : $(OBJ_DIR)
	$(MAKE) -C libft
	$(MAKE) -C minilibx_mms_20200219
	mv ./minilibx_mms_20200219/libmlx.dylib ./
	$(CC) $(CFLAGS) -o $@ $^ ./libft/libft.a libmlx.dylib $(FRAMEWORK)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADER)
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

.PHONY: all clean fclean re