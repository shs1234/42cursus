CC = gcc -Wall -Wextra -Werror
NAME = bsq
OBJS = main.o ft_valid_map.o ft_split.o ft_file.o ft_util.o ft_calc.o

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $@ $^

.c.o :
	$(CC) -c -o $@ $<
    
clean :
	rm -rf $(OBJS)
	
fclean : clean
	rm -rf $(NAME)

re : fclean all