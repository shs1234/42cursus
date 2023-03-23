# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 14:34:05 by hoseoson          #+#    #+#              #
#    Updated: 2023/03/22 21:51:22 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar r
RM		=	rm -rf
HEADER	=	libft.h

SRCS	=	ft_strchr.c ft_split.c ft_strtrim.c ft_bzero.c ft_strnstr.c \
	ft_strmapi.c ft_isprint.c ft_atoi.c ft_strdup.c ft_tolower.c ft_toupper.c \
	ft_substr.c ft_striteri.c ft_memchr.c ft_putnbr_fd.c ft_strlcpy.c ft_itoa.c \
	ft_memset.c ft_calloc.c ft_strlen.c ft_putchar_fd.c ft_isascii.c \
	ft_strlcat.c ft_putendl_fd.c ft_memcmp.c ft_isdigit.c ft_strrchr.c \
	ft_putstr_fd.c ft_isalpha.c ft_strncmp.c ft_isalnum.c ft_memcpy.c \
	ft_memmove.c ft_strjoin.c

SRCS_B	=	ft_lstadd_front.c ft_lstnew.c ft_lstmap.c \
	ft_lstclear.c ft_lstadd_back.c ft_lstsize.c \
	ft_lstlast.c ft_lstdelone.c ft_lstiter.c

OBJS	=	$(SRCS:.c=.o)
OBJS_B	=	$(SRCS_B:.c=.o)

ifdef WITH_BONUS
	OBJ_SWITCH = $(OBJS) $(OBJS_B) 
else
	OBJ_SWITCH = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJ_SWITCH)
	$(AR) $@ $^

bonus :
	$(MAKE) WITH_BONUS=1 $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus