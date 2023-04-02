#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(void)
{
	int fd[4];
	fd[0] = open("test.txt", O_RDWR);
	fd[1] = open("test.txt", O_RDWR);
	fd[2] = open("test.txt", O_RDWR);
	fd[3] = open("test.txt", O_RDWR);
	printf("%s", get_next_line(fd[0]));
	printf("%s", get_next_line(fd[1]));
	printf("%s", get_next_line(fd[2]));
	printf("%s", get_next_line(fd[3]));
	printf("%s", get_next_line(fd[0]));
	printf("%s", get_next_line(fd[1]));
	printf("%s", get_next_line(fd[2]));
	printf("%s", get_next_line(fd[3]));
	printf("%s", get_next_line(fd[0]));
	printf("%s", get_next_line(fd[1]));
	printf("%s", get_next_line(fd[2]));
	printf("%s", get_next_line(fd[3]));
	printf("%s", get_next_line(fd[0]));
	printf("%s", get_next_line(fd[1]));
	printf("%s", get_next_line(fd[2]));
	printf("%s", get_next_line(fd[3]));
	// system("leaks a.out");
}