/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 02:00:02 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/05 02:00:02 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint_fd(unsigned int n, int fd)
{
	int tab[10];
	int i;
	int len;

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