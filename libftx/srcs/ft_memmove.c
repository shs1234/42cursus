/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:49:39 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/11 03:42:24 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*uc_src;
	unsigned char		*uc_dst;

	uc_dst = dst;
	uc_src = src;
	if (uc_dst > uc_src)
		while (len-- > 0)
			uc_dst[len] = uc_src[len];
	else if (uc_dst < uc_src)
		while (len-- > 0)
			*uc_dst++ = *uc_src++;
	return (dst);
}
