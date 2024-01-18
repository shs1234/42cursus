# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 22:35:13 by hoseoson          #+#    #+#              #
#    Updated: 2024/01/18 20:22:39 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			=	c++
NAME		=	PmergeMe
RM			=	rm -rf
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
CXXFLAGS	=	

SRCS		=	$(wildcard *.cpp)
HEADERS		=	$(wildcard *.hpp)
OBJS		=	$(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o : %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
