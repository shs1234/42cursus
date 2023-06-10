# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 22:35:13 by hoseoson          #+#    #+#              #
#    Updated: 2023/06/11 06:20:19 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
LIB			= 	libft/libft.a

SRC_DIR 	= 	mandatory/srcs
OBJ_DIR 	= 	mandatory/objs
SRCS 		= 	$(wildcard $(SRC_DIR)/*.c)
OBJS 		= 	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
HEADER      =   $(SRC_DIR)/minishell.h

SRC_DIR_B 	= 	bonus/srcs
OBJ_DIR_B 	= 	bonus/objs
SRCS_B 		= 	$(wildcard $(SRC_DIR_B)/*.c)
OBJS_B 		= 	$(patsubst $(SRC_DIR_B)/%.c,$(OBJ_DIR_B)/%.o,$(SRCS_B))
HEADER_B    =   $(SRC_DIR_B)/minishell_bonus.h

ifdef BONUS
	SWITCH_OBJS 	=	$(OBJS_B)
	SWITCH_HEADER	=	$(HEADER_B)
	SWITCH_SRC_DIR 	=	$(SRC_DIR_B)
	SWITCH_OBJ_DIR 	=	$(OBJ_DIR_B)
else
	SWITCH_OBJS 	=	$(OBJS)
	SWITCH_HEADER 	=	$(HEADER)
	SWITCH_SRC_DIR 	=	$(SRC_DIR)
	SWITCH_OBJ_DIR 	=	$(OBJ_DIR)
endif

all : $(SWITCH_OBJ_DIR) $(NAME)

bonus :
	$(MAKE) BONUS=1 all

$(SWITCH_OBJ_DIR) :
	mkdir -p $@

$(NAME) : $(SWITCH_OBJS)
	# $(MAKE) -C libft
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(SWITCH_OBJ_DIR)/%.o : $(SWITCH_SRC_DIR)/%.c $(SWITCH_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean : 
	# $(MAKE) -C libft $@
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	# $(MAKE) -C libft $@
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
