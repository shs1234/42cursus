/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 01:59:53 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/06 14:36:38 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_lower(unsigned int n)
{
	char	hex[8];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		len++;
	}
	while (n)
	{
		hex[i++] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	while (i)
	{
		if (write(1, &hex[--i], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_print_hex_upper(unsigned int n)
{
	char	hex[8];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		len++;
	}
	while (n)
	{
		hex[i++] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	while (i)
	{
		if (write(1, &hex[--i], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}
