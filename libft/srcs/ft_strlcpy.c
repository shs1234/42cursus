/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:17:16 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/11 04:36:19 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	if (dstsize == 0)
		return (ft_strlen(src));
	src_len = ft_strlen(src);
	while (--dstsize && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (src_len);
}
