/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:08:02 by hoseoson          #+#    #+#             */
/*   Updated: 2023/07/07 01:38:07 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*dup_start;
	size_t	len;

	len = ft_strlen(s1);
	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	dup_start = dup;
	while (len--)
		*dup++ = *s1++;
	*dup = '\0';
	return (dup_start);
}
