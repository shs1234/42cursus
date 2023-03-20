#include <stdio.h>
#include "libft.h"
#include <string.h>

int	main(void)
{
	// char *s1 = "oh no not the empty string !";
	// char *s2 = "";
	// size_t max = 0;
	strnstr("fake", ((void *)0), 3);
	ft_strnstr("fake", ((void *)0), 3);
	// char *i1 = strnstr(s1, s2, max);
	// char *i2 = ft_strnstr(s1, s2, max);
	// printf("ori : %s\nmy  : %s\n", i1, i2);
}
