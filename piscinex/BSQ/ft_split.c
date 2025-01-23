/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:32:53 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/31 19:01:00 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src, int len)
{
	char	*dup;
	int		i;

	i = 0;
	if (len == -1)
	{
		len = 0;
		while (src[len])
			len++;
	}
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (!dup)
		return (0);
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		start;
	int		end;
	int		i;

	i = 0;
	split = (char **)malloc(sizeof(char *) * (ft_strlen(str) + 1));
	if (!split)
		return (0);
	start = 0;
	while (str[start])
	{
		if (ft_in_charset(str[start], charset))
		{
			start++;
			continue ;
		}
		end = start;
		while (!ft_in_charset(str[end], charset) && str[end])
			end++;
		split[i++] = ft_strdup(&str[start], end - start);
		start = end;
	}
	split[i] = 0;
	return (split);
}
