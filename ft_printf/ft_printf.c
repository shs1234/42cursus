/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:35:38 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/18 01:54:15 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printarg(char c, va_list ap, int *len)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret = ft_putchar_fd(va_arg(ap, int), 1);
	else if (c == 's')
		ret = ft_putstr_fd(va_arg(ap, char *), 1);
	else if (c == 'p')
		ret = ft_putaddr(va_arg(ap, void *));
	else if (c == 'd')
		ret = ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'i')
		ret = ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'u')
		ret = ft_putuint_fd(va_arg(ap, unsigned int), 1);
	else if (c == 'x')
		ret = ft_print_hex_lower(va_arg(ap, unsigned int));
	else if (c == 'X')
		ret = ft_print_hex_upper(va_arg(ap, unsigned int));
	else if (c == '%')
		ret = write(1, "%", 1);
	if (ret == -1)
		return (0);
	(*len) += ret;
	return (1);
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
			if (ft_strchr("cspdiuxX%", *format))
			{
				if (!ft_printarg(*format, ap, &len))
					return (-1);
			}
		}
		else
		{
			if (ft_putchar_fd(*format, 1) == -1)
				return (-1);
			len++;
		}
		format++;
	}
	return (va_end(ap), len);
}
