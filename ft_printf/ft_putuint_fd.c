/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 02:00:02 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/05 13:38:01 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint_fd(unsigned int n, int fd)
{
	int	tab[10];
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (n == 0)
		len += ft_putchar_fd(0 + '0', fd);
	while (n)
	{
		tab[i++] = n % 10;
		n /= 10;
	}
	while (i--)
		len += ft_putchar_fd(tab[i] + '0', fd);
	return (len);
}
