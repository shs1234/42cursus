/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:49:39 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/17 20:35:12 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*uc_src;
	unsigned char	*uc_dst;

	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	if (uc_dst > uc_src)
	{
		while (len > 0)
		{
			uc_dst[len - 1] = uc_src[len - 1];
			len--;
		}
	}
	else if (uc_dst < uc_src)
	{
		while (len > 0)
		{
			*uc_dst = *uc_src;
			uc_dst++;
			uc_src++;
			len--;
		}
	}
	return (dst);
}
