/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:59:07 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/15 10:18:41 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*uc_s1;
	const unsigned char	*uc_s2;

	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (uc_s1[i] && uc_s2[i] && i < n)
	{
		if (uc_s1[i] == uc_s2[i])
			i++;
		else
			return ((unsigned char)uc_s1[i] - (unsigned char)uc_s2[i]);
	}
	if (i == n)
		return (0);
	else
		return ((unsigned char)uc_s1[i] - (unsigned char)uc_s2[i]);
}
