/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 01:59:50 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/29 23:16:55 by hoseoson         ###   ########.fr       */
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
		if (ft_putchar_ret(tab[--i]) == -1)
			return (0);
		(*len)++;
	}
	return (1);
}

int	ft_putaddr(void *addr)
{
	int	len;

	if (ft_putstr_ret("0x") == -1)
		return (-1);
	len = 2;
	if (!addr)
	{
		if (ft_putchar_ret('0') == -1)
			return (-1);
		len++;
	}
	if (!ft_print_addr(addr, &len))
		return (-1);
	return (len);
}
