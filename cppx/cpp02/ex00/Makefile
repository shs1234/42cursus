# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 22:35:13 by hoseoson          #+#    #+#              #
#    Updated: 2023/08/26 23:53:23 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			=	c++
NAME		=	a.out
RM			=	rm -rf
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
