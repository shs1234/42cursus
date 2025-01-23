# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 14:34:05 by hoseoson          #+#    #+#              #
#    Updated: 2023/04/23 15:57:06 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rcs
RM		=	rm -rf
HEADER	=	libft.h

SRCS	=	ft_strchr.c ft_split.c ft_strtrim.c ft_bzero.c ft_strnstr.c \
			ft_strmapi.c ft_isprint.c ft_atoi.c ft_strdup.c ft_tolower.c \
			ft_toupper.c ft_substr.c ft_striteri.c ft_memchr.c ft_putnbr_fd.c \
			ft_strlcpy.c ft_itoa.c ft_memset.c ft_calloc.c ft_strlen.c \
			ft_putchar_fd.c ft_isascii.c ft_strlcat.c ft_putendl_fd.c ft_memcmp.c \
			ft_isdigit.c ft_strrchr.c ft_putstr_fd.c ft_isalpha.c ft_strncmp.c \
			ft_isalnum.c ft_memcpy.c ft_memmove.c ft_strjoin.c ft_lstadd_front.c \
			ft_lstnew.c ft_lstmap.c ft_lstclear.c ft_lstadd_back.c ft_lstsize.c \
			ft_lstlast.c ft_lstdelone.c ft_lstiter.c

OBJS	=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $@ $^

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re