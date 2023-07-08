# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 00:56:33 by hoseoson          #+#    #+#              #
#    Updated: 2023/07/09 07:23:36 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = philo
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf

SRC_DIR 	= srcs
OBJ_DIR 	= objs
SRCS 		= $(wildcard $(SRC_DIR)/*.c)
OBJS 		= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
HEADER		= philo.h

all : $(OBJ_DIR) $(NAME)

$(OBJ_DIR) :
	mkdir -p $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(SRC_DIR)/$(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
