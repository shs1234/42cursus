
#include "ft_printf.h"

int	main(void)
{
	char *ptr = "123";
	printf("%d\n", printf("123 %p %d %i %u %X %x %%\n", ptr, 123, 123, -123,
				123, 123));
	printf("%d\n", ft_printf("123 %p %d %i %u %X %x %%\n", ptr, 123, 123, -123,
				123, 123));
}