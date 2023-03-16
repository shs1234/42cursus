/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:49:39 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/14 20:13:09 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*uc_src;
	unsigned char	*uc_dst;
	size_t			i;

	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	if (uc_dst < uc_src)
	{
		i = len - 1;
		while (i >= 0)
		{
			uc_dst[i] = uc_src[i];
			i--;
		}
	}
	else if (uc_dst > uc_src)
	{
		i = 0;
		while (i < len)
		{
			uc_dst[i] = uc_src[i];
			i++;
		}
	}
	return (dst);
}
