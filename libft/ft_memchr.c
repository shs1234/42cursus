/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:10:23 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/15 09:50:53 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*uc_s;
	unsigned char		uc_c;

	uc_s = (unsigned char *)s;
	uc_c = (unsigned char)c;
	while (n--)
	{
		if (*uc_s == uc_c)
			return ((void *)uc_s);
		uc_s++;
	}
	return (0);
}
