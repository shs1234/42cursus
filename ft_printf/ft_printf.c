/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:35:38 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/04 04:26:29 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printarg(char c, va_list ap)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(ap, char), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (c == 'p')
		ft_print_addr(va_arg(ap, void *));
	else if (c == 'd')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'u')
		ft_putuint_fd(va_arg(ap, int), 1);
	else if (c == 'x')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'X')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == '%')
		ft_putchar_fd(va_arg(ap, char), 1);
}
// char int promote에 대해 공부중이었음. 위 함수들은 자료형만 조절해주면됨
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	c;
	int		i;
	char	*str;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_printarg(*format, ap);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(ap);
	return (0);
}
void	ft_print_hex_lower(unsigned int n)
{
	char	hex[8];
	int		i;

	i = 0;
	while (n)
	{
		hex[i++] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	while (i)
		write(1, &hex[--i], 1);
}

void	ft_print_hex_upper(unsigned int n)
{
	char	hex[8];
	int		i;

	i = 0;
	while (n)
	{
		hex[i++] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	while (i)
		write(1, &hex[--i], 1);
}
int	main(void)
{
	printf("%x\n", );
	ft_print_hex();
	// ft_printf("aaa%caa%sa%paaa", 'b', "zzz", "q");
}