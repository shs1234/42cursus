/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:35:38 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/03 23:44:02 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	c;

	va_start(ap, format);
	c = va_arg(ap, int);
	write(1, &c, 1);
	c = va_arg(ap, int);
	write(1, &c, 1);
	c = va_arg(ap, int);
	write(1, &c, 1);
	c = va_arg(ap, int);
	write(1, &c, 1);
	va_end(ap);
	return (0);
}

int	main(void)
{
	ft_printf("123", '5', '7');
}