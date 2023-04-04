/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:28:56 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/04 16:04:11 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	long long	lln;
	int			tab[10];
	int			i;
	int			len;

	lln = n;
	i = 0;
	len = 0;
	if (lln == 0)
	{
		ft_putchar_fd(0 + '0', fd);
		len++;
	}
	if (lln < 0)
	{
		ft_putchar_fd('-', fd);
		lln *= -1;
		len++;
	}
	while (lln)
	{
		tab[i++] = lln % 10;
		lln /= 10;
	}
	len += i;
	while (i--)
		ft_putchar_fd(tab[i] + '0', fd);
	return (len);
}

int	ft_putuint_fd(unsigned int n, int fd)
{
	int	tab[10];
	int	i;
	int	len;

	i = 0;
	if (n == 0)
		ft_putchar_fd(0 + '0', fd);
	while (n)
	{
		tab[i++] = n % 10;
		n /= 10;
	}
	len = i;
	while (i--)
		ft_putchar_fd(tab[i] + '0', fd);
	return (len);
}

int	ft_print_hex_lower(unsigned int n)
{
	char	hex[8];
	int		i;
	int		len;

	i = 0;
	while (n)
	{
		hex[i++] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	len = i;
	while (i)
		write(1, &hex[--i], 1);
	return (len);
}

int	ft_print_hex_upper(unsigned int n)
{
	char	hex[8];
	int		i;
	int		len;

	i = 0;
	while (n)
	{
		hex[i++] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	len = i;
	while (i)
		write(1, &hex[--i], 1);
	return (len);
}

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
