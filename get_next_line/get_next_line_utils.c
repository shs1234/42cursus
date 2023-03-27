/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:36:08 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/27 11:16:20 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*lst;
	int i;
	int len;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (0);
	len = 0;
	while (content[len])
		len++;
	lst->content = (char *)malloc(sizeof(char) * len + 1);
	if (!lst->content)
		return (0);
	i = 0;
	while (i < len)
	{
		lst->content[i] = content[i];
		i++;
	}
	lst->content[i] = 0;
	lst->next = 0;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastlst;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lastlst = ft_lstlast(*lst);
	lastlst->next = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst && lst->next)
	{
		while (lst)
		{
			if (!lst->next)
				return (lst);
			lst = lst->next;
		}
	}
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
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
		word = ft_substr(s, start, end - start + 1);
		split[i++] = word;
		if (!word)
			return (--i);
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

	if (!s)
		return (0);
	count = ft_countword(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (0);
	if (ft_splitword(split, s, c) < count)
	{
		i = 0;
		while (split[i])
			free(split[i++]);
		free(split);
		split = 0;
	}
	return (split);
}
