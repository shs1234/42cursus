/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:41:56 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/20 02:56:05 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
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
static size_t	ft_splitword(char **split, char const *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;

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
		if (!(split[i++] = ft_substr(s, start, end - start)))
			return (i);
		start = end;
	}
	split[i] = 0;
	return (i);
}
char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	count;

	count = ft_countword(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (0);
	if (ft_splitword(split, s, c) < count)
	{
		while(*split)
			free(*split++);
		free(split);
		split = 0;
	}
	return (split);
}
