#include <stdio.h>
#include "libft.h"

int main()
{
	char *str;
	str = ft_strtrim("AAAAAccBBBBA"  , "AB");
	printf("%s\n", str);
	
}
