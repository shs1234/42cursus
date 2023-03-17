/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:41:56 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/17 14:24:02 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;
	size_t	start;
	size_t	end;

	start = 0;
	count = 0;
	while (s[start])
	{
		if (s[start] == c)
		{
			start++;
			continue ;
		}
		end = start;
		while (s[end] != c && s[end])
			end++;
		count++;
		start = end;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	start;
	size_t	end;
	size_t	i;

	split = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!split)
		return (0);
	i = 0;
	start = 0;
	while (s[start])
	{
		if (s[start] == c)
		{
			start++;
			continue ;
		}
		end = start;
		while (s[end] != c && s[end])
			end++;
		split[i++] = ft_substr(s, start, end - start);
		start = end;
	}
	split[i] = 0;
	return (split);
}
