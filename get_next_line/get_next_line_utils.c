/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:36:08 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/28 13:18:15 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_has_newline(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strjoin(char *ret, char *buf, int pos)
{
	char	*join;
	char	*join_start;
	char	*tmp;
	size_t	ret_len;

	if (!ret)
		ret_len = 0;
	else
		ret_len = ft_strlen(ret);
	if (pos == -1)
		pos = ft_strlen(buf) - 1;
	join = (char *)malloc(sizeof(char) * (ret_len + pos + 2));
	if (!join)
		return (0);
	join_start = join;
	tmp = ret;
	while (ret_len--)
		*join++ = *ret++;
	pos++;
	while (pos--)
		*join++ = *buf++;
	*join = '\0';
	free(tmp);
	return (join_start);
}

char	*ft_strdup(char *save, char *s1)
{
	char	*dup;
	char	*dup_start;
	size_t	len;

	if (!s1)
		len = 0;
	else
		len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (!dup)
		return (0);
	dup_start = dup;
	while (len--)
		*dup++ = *s1++;
	*dup = 0;
	free(save);
	return (dup_start);
}
// t_list	*ft_lstnew(char *content)
// {
// 	t_list	*lst;
// 	size_t	i;
// 	size_t	len;

// 	lst = (t_list *)malloc(sizeof(t_list));
// 	if (!lst)
// 		return (0);
// 	len = 0;
// 	while (content[len])
// 		len++;
// 	lst->content = (char *)malloc(sizeof(char) * len + 1);
// 	if (!lst->content)
// 		return (0);
// 	i = 0;
// 	while (i < len)
// 	{
// 		lst->content[i] = content[i];
// 		i++;
// 	}
// 	lst->content[i] = 0;
// 	lst->next = 0;
// 	return (lst);
// }

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*lastlst;

// 	if (!*lst)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	lastlst = ft_lstlast(*lst);
// 	lastlst->next = new;
// }

// t_list	*ft_lstlast(t_list *lst)
// {
// 	if (lst && lst->next)
// 	{
// 		while (lst)
// 		{
// 			if (!lst->next)
// 				return (lst);
// 			lst = lst->next;
// 		}
// 	}
// 	return (lst);
// }

// int	ft_lstsize(t_list *lst)
// {
// 	int	size;

// 	size = 0;
// 	while (lst)
// 	{
// 		size++;
// 		lst = lst->next;
// 	}
// 	return (size);
// }

// static size_t	ft_countword(char const *s, char c)
// {
// 	size_t	count;
// 	size_t	start;
// 	size_t	end;

// 	start = 0;
// 	count = 0;
// 	while (s[start])
// 	{
// 		if (s[start] == c)
// 		{
// 			start++;
// 			continue ;
// 		}
// 		end = start;
// 		while (s[end] != c && s[end])
// 			end++;
// 		count++;
// 		start = end;
// 	}
// 	return (count);
// }

// static size_t	ft_splitword(char **split, char const *s, char c)
// {
// 	size_t	start;
// 	size_t	end;
// 	size_t	i;
// 	char	*word;

// 	i = 0;
// 	start = 0;
// 	while (s[start])
// 	{
// 		if (s[start] == c)
// 		{
// 			start++;
// 			continue ;
// 		}
// 		end = start;
// 		while (s[end] != c && s[end])
// 			end++;
// 		word = ft_substr(s, start, end - start + 1);
// 		if (!word)
// 			return (i);
// 		split[i++] = word;
// 		start = end;
// 	}
// 	split[i] = 0;
// 	return (i);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**split;
// 	size_t	count;
// 	size_t	i;
// 	size_t	split_i;

// 	if (!s)
// 		return (0);
// 	count = ft_countword(s, c);
// 	split = (char **)malloc(sizeof(char *) * (count + 1));
// 	if (!split)
// 		return (0);
// 	split_i = ft_splitword(split, s, c);
// 	if (split_i < count)
// 	{
// 		i = 0;
// 		while (i < split_i)
// 		{
// 			free(split[i]);
// 			i++;
// 		}
// 		free(split);
// 		split = 0;
// 	}
// 	return (split);
// }

