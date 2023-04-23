/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 01:59:50 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/06 14:06:31 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_addr(void *addr, int *len)
{
	char				tab[16];
	int					i;
	unsigned long long	ull_addr;

	i = 0;
	ull_addr = (unsigned long long)addr;
	while (ull_addr)
	{
		tab[i++] = "0123456789abcdef"[ull_addr % 16];
		ull_addr /= 16;
	}
	while (i)
	{
		if (write(1, &tab[--i], 1) == -1)
			return (0);
		(*len)++;
	}
	return (1);
}

int	ft_putaddr(void *addr)
{
	int	len;

	len = 0;
	if (write(1, "0x", 2) == -1)
		return (-1);
	len += 2;
	if (!addr)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		len++;
	}
	if (!ft_print_addr(addr, &len))
		return (-1);
	return (len);
}
