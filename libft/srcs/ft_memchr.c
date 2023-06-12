/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:10:23 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/11 03:36:25 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*uc_s;
	unsigned char		uc_c;

	uc_s = s;
	uc_c = c;
	while (n--)
	{
		if (*uc_s == uc_c)
			return ((void *)uc_s);
		uc_s++;
	}
	return (0);
}
