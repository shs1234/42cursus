#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("test", O_RDONLY);
	while (i < 9)
	{
		line = get_next_line(fd);
		printf(">>>>>%d : %s", i + 1, line);
		free(line);
		i++;
	}
	// printf("\n");
	system("leaks a.out");
}
