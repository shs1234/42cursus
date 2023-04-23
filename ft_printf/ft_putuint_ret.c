/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 02:00:02 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/22 03:47:30 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint_ret(unsigned int n)
{
	int	tab[10];
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (n == 0)
	{
		if (ft_putchar_ret(0 + '0') == -1)
			return (-1);
		len++;
	}
	while (n)
	{
		tab[i++] = n % 10;
		n /= 10;
	}
	while (i--)
	{
		if (ft_putchar_ret(tab[i] + '0') == -1)
			return (-1);
		len++;
	}
	return (len);
}
