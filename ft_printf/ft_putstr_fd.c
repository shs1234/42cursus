/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:16:22 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/05 13:27:35 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	if (s)
	{
		while (*s)
			len += ft_putchar_fd(*s++, fd);
	}
	else
		len += write(1, "(null)", 6);
	return (len);
}
