/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 01:59:50 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/05 01:59:51 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_addr(void *addr)
{
	int					i;
	unsigned long long	ull;
	char				tab[16];
	int					len;

	i = 0;
	len = 0;
	ull = (unsigned long long)addr;
	write(1, "0x", 2);
	len += 2;
	while (ull)
	{
		tab[i] = "0123456789abcdef"[ull % 16];
		ull /= 16;
		i++;
	}
	len += i;
	while (i)
		write(1, &tab[--i], 1);
	return (len);
}
