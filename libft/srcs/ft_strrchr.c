/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:11:19 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/11 05:52:21 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s_start;
	char		char_c;

	char_c = (char)c;
	s_start = s;
	while (*s)
		s++;
	while (s_start != s)
	{
		if (*s == char_c)
			return ((char *)s);
		s--;
	}
	if (*s == char_c)
		return ((char *)s);
	return (NULL);
}
