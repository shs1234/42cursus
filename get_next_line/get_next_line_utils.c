/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:36:08 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/25 11:36:29 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->content = content;
	lst->next = 0;
	return (lst);
}
void	ft_strcpy(char *dst, char *buf, int len)
{
	int	i;
	
	i = 0;
	while (i < len)
	{
		dst[i] = buf[i];
		i++;
	}
	// dst[i] = 0;
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
void	ft_strlcat(char *dst, const char *src, int end, int *len)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		dst[*len + i] = src[i];
		i++;
	}
	if (end == 0)
		dst[*len + i] = '\n';
	else
		dst[*len + i] = 0;
	*len += i;
}
