/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:15:15 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/19 18:05:38 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_addr(void *addr)
{
	int					i;
	unsigned long long	ull;
	char				tab[16];

	i = 0;
	ull = (unsigned long long)addr;
	while (i < 16)
	{
		tab[i] = "0123456789abcdef"[ull % 16];
		ull /= 16;
		i++;
	}
	while (i-- > 0)
		write(1, &tab[i], 1);
	write(1, ": ", 2);
}

void	ft_print_hex(unsigned char *addr, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		write(1, &"0123456789abcdef"[addr[i] / 16], 1);
		write(1, &"0123456789abcdef"[addr[i] % 16], 1);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	ft_print_text(char *addr, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (!(addr[i] >= 32 && addr[i] <= 126))
			write(1, ".", 1);
		else
			write(1, &addr[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 16;
	while (i < size)
	{
		if ((size - i) / 16 < 1)
			n = size % 16;
		ft_print_addr(&addr[i]);
		ft_print_hex(&addr[i], n);
		ft_print_text(&addr[i], n);
		i += 16;
	}
	return (addr);
}
