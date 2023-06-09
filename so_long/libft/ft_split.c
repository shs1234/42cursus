/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:41:56 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/28 02:07:04 by hoseoson         ###   ########.fr       */
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
	char	*word;

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
		word = ft_substr(s, start, end - start);
		if (!word)
			return (i);
		split[i++] = word;
		start = end;
	}
	split[i] = 0;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	count;
	size_t	i;
	size_t	split_i;

	if (!s)
		return (0);
	count = ft_countword(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (0);
	split_i = ft_splitword(split, s, c);
	if (split_i < count)
	{
		i = 0;
		while (i < split_i)
		{
			free(split[i]);
			i++;
		}
		free(split);
		split = 0;
	}
	return (split);
}
