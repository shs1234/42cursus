/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:47:49 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/11 03:24:25 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*num;
	size_t		numlen;
	long long	lln;

	numlen = ft_numlen(n);
	lln = n;
	num = malloc(sizeof(char) * numlen + 1);
	if (!num)
		return (0);
	if (lln == 0)
		num[0] = '0';
	if (lln < 0)
	{
		num[0] = '-';
		lln *= -1;
	}
	num[numlen--] = 0;
	while (lln)
	{
		num[numlen--] = (lln % 10) + '0';
		lln /= 10;
	}
	return (num);
}
