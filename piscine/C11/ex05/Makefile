CC = gcc -Wall -Wextra -Werror
TARGET = do-op
OBJS = ft_atoi.o ft_putnbr.o main.o ft_opers.o

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