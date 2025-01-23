TARGET = libft.a 
CC = gcc -Wall -Wextra -Werror
OBJS = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	ar r $(TARGET) $(OBJS)

%.o : %.c
	$(CC) -c $< -o $@ -I ./includes/

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(TARGET)

re : fclean all