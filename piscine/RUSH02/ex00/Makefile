CC = gcc -Wall -Wextra -Werror
TARGET = rush-02
OBJS = main.o ft_split.o file.o convert_to_str.o print_func.o util_func.o rush_atoi.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

.c.o :
	$(CC) -c -o $@ $<
    
clean :
	rm -rf $(OBJS)
	
fclean : clean
	rm -rf $(TARGET)

re : fclean all