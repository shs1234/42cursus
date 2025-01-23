/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:21:24 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/11 05:51:07 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ndl_len;
	size_t	hay_len;
	size_t	end;

	if (!*needle)
		return ((char *)haystack);
	if (len)
	{
		i = 0;
		ndl_len = ft_strlen(needle);
		hay_len = ft_strlen(haystack);
		if (hay_len < ndl_len)
			return (0);
		end = hay_len - ndl_len;
		while (i + ndl_len <= len && i <= end)
		{
			if (!ft_strncmp(haystack, needle, ndl_len))
				return ((char *)haystack);
			i++;
			haystack++;
		}
	}
	return (0);
}
