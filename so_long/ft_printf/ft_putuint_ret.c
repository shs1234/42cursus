/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_ret.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 02:00:02 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/29 23:02:14 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint_ret(unsigned int n)
{
	int	tab[10];
	int	i;
	int	len;

	if (n == 0)
		return (ft_putchar_ret('0'));
	i = 0;
	len = 0;
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
