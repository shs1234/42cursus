# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 22:35:13 by hoseoson          #+#    #+#              #
#    Updated: 2023/07/03 21:06:14 by gibkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -I/Users/$(shell whoami)/.brew/opt/readline/include
LIB			= 	libft/libft.a -lncurses -lreadline -L/Users/$(shell whoami)/.brew/opt/readline/lib

SRC_DIR 	= 	srcs
OBJ_DIR 	= 	objs
SRCS 		= 	$(wildcard $(SRC_DIR)/*.c)
OBJS 		= 	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
HEADER      =   $(SRC_DIR)/minishell.h

all : $(OBJ_DIR) $(NAME)

$(OBJ_DIR) :
	mkdir -p $@

$(NAME) : $(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean : 
	$(MAKE) -C libft $@
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C libft $@
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
