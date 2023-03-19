#include <stdio.h>
#include "libft.h"

int main(void)
{
	char **split = ft_split("   a asd asddd asd   ", ' ');
	while(*split)
		printf("%s\n", *split++);
}