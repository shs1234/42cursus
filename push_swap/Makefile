# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 22:35:13 by hoseoson          #+#    #+#              #
#    Updated: 2023/06/01 21:43:08 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rcs
RM			=	rm -rf

NAME		=	push_swap
SRC_DIR 	= 	mandatory/srcs
OBJ_DIR 	= 	mandatory/objs
SRCS 		= 	$(wildcard $(SRC_DIR)/*.c)
OBJS 		= 	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
HEADER      =   $(SRC_DIR)/push_swap.h

NAME_B		=	checker
SRC_DIR_B 	= 	bonus/srcs
OBJ_DIR_B 	= 	bonus/objs
SRCS_B 		= 	$(wildcard $(SRC_DIR_B)/*.c)
OBJS_B 		= 	$(patsubst $(SRC_DIR_B)/%.c,$(OBJ_DIR_B)/%.o,$(SRCS_B))
HEADER_B    =   $(SRC_DIR_B)/push_swap_bonus.h

ifdef BONUS
	SWITCH_NAME		=	$(NAME_B)
	SWITCH_OBJS 	=	$(OBJS_B)
	SWITCH_HEADER	=	$(HEADER_B)
	SWITCH_SRC_DIR 	=	$(SRC_DIR_B)
	SWITCH_OBJ_DIR 	=	$(OBJ_DIR_B)
else
	SWITCH_NAME 	=	$(NAME)
	SWITCH_OBJS 	=	$(OBJS)
	SWITCH_HEADER 	=	$(HEADER)
	SWITCH_SRC_DIR 	=	$(SRC_DIR)
	SWITCH_OBJ_DIR 	=	$(OBJ_DIR)
endif

all : $(SWITCH_NAME)

bonus :
	$(MAKE) BONUS=1 all

$(SWITCH_NAME) : $(SWITCH_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(SWITCH_OBJ_DIR)/%.o : $(SWITCH_SRC_DIR)/%.c $(SWITCH_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean : 
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(RM) $(NAME) $(NAME_B)

re : fclean all

.PHONY: all clean fclean re bonus