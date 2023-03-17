#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{

	char *str;
	str = 0;
	// strnstr("fake", ((void *)0), 3);
	// printf("%s", strnstr((void *)0, "fake", 0));
	// printf("%s\n", ft_strnstr((void *)0, "fake", 0));
	// printf("%s\n", strnstr(((void *)0), "fake", 3));
	// printf("%s\n", ft_strnstr(((void *)0), "fake", 3));
	
	// ft_strnstr(((void *)0), "fake", 0);

	char *s1 = "oh no not the empty string !";
	char *s2 = "";
	size_t max = 0;
	char *i1 = strnstr(s1, s2, max);
	char *i2 = ft_strnstr(s1, s2, max);
	printf("%s, %s",i1, i2);

}
