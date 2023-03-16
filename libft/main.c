#include<stdio.h>
#include "libft.h"

int main()
{
	char *str;
	str = ft_strtrim("AAAAABBBBA"  , "AB");
	printf("%s", str);
	
}
