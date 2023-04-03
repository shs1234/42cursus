/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:28:56 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/04 04:26:32 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	lln;
	int			tab[10];
	int			i;

	lln = n;
	i = 0;
	if (lln == 0)
		ft_putchar_fd(0 + '0', fd);
	if (lln < 0)
	{
		ft_putchar_fd('-', fd);
		lln *= -1;
	}
	while (lln)
	{
		tab[i++] = lln % 10;
		lln /= 10;
	}
	while (--i > 0)
		ft_putchar_fd(tab[i] + '0', fd);
}
void	ft_putuint_fd(unsigned int n, int fd)
{
	int	tab[10];
	int	i;

	i = 0;
	if (n == 0)
		ft_putchar_fd(0 + '0', fd);
	while (n)
	{
		tab[i++] = n % 10;
		n /= 10;
	}
	while (--i > 0)
		ft_putchar_fd(tab[i] + '0', fd);
}
void	ft_print_hex_lower(unsigned int n)
{
	char	hex[8];
	int		i;

	i = 0;
	while (n)
	{
		hex[i++] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	while (i)
		write(1, &hex[--i], 1);
}

void	ft_print_hex_upper(unsigned int n)
{
	char	hex[8];
	int		i;

	i = 0;
	while (n)
	{
		hex[i++] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	while (i)
		write(1, &hex[--i], 1);
}
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
}
