/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:16:22 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/13 19:10:26 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_ret(char *s)
{
	int	len;

	len = 0;
	if (s)
	{
		while (*s)
		{
			if (write(1, s++, 1) == -1)
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