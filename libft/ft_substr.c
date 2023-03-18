/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:26:19 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/18 13:09:38 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (ft_strlen(s) <= start)
		len = 0;
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (0);
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}
