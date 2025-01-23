# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 23:12:02 by hoseoson          #+#    #+#              #
#    Updated: 2024/03/12 13:48:59 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR 	= 	srcs
OBJ_DIR 	= 	objs
HDR_DIR		=	includes
SOURCES 	= 	$(shell find $(SRC_DIR) -name "*.cpp")
OBJECTS 	= 	$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
HEADERS		= 	$(wildcard $(HDR_DIR)/*.hpp)

TARGET		=	ircserv
CXX			=	c++
RM			=	rm -rf
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
INCLUDES 	=	-I$(HDR_DIR)

all : $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(TARGET)

re : fclean all

.PHONY: all clean fclean re
