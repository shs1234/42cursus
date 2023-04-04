/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:35:38 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/04 16:12:36 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printarg(char c, va_list ap)
{
	int	fd;
	int	len;

	len = 0;
	fd = 1;
	if (c == 'c')
		len += ft_putchar_fd(va_arg(ap, int), fd);
	else if (c == 's')
		len += ft_putstr_fd(va_arg(ap, char *), fd);
	else if (c == 'p')
		len += ft_print_addr(va_arg(ap, void *));
	else if (c == 'd')
		len += ft_putnbr_fd(va_arg(ap, int), fd);
	else if (c == 'i')
		len += ft_putnbr_fd(va_arg(ap, int), fd);
	else if (c == 'u')
		len += ft_putuint_fd(va_arg(ap, unsigned int), fd);
	else if (c == 'x')
		len += ft_print_hex_lower(va_arg(ap, unsigned int));
	else if (c == 'X')
		len += ft_print_hex_upper(va_arg(ap, unsigned int));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				len += ft_putchar_fd(*format, 1);
			else
				len += ft_printarg(*format, ap);
		}
		else
			len += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(ap);
	return (len);
}
