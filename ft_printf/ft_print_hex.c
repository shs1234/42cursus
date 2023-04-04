/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 01:59:53 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/05 01:59:54 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	char hex[8];
	int i;
	int len;

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