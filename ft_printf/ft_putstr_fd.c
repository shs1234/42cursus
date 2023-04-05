/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:16:22 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/05 22:43:56 by hoseoson         ###   ########.fr       */
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
		{
			if (write(fd, s++, 1) == -1)
				return (-1);
			len++;
		}
	}
	else
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		len += 6;
	}
	return (len);
}
