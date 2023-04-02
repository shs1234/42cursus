/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:08:58 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/03 01:18:27 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

void	ft_free(char **mem)
{
	free(*mem);
	*mem = 0;
}

// t_list	*ft_findfd(t_list **head, int fd)
// {
// 	t_list	*node;

// 	node = *head;
// 	if (!node)
// 	{
// 		node = (t_list *)malloc(sizeof(t_list));
// 		if (!node)
// 			return (NULL);
// 		node->fd = fd;
// 		node->save = 0;
// 		node->next = 0;
// 		return (node);
// 	}
// 	while (node)
// 	{
// 		if (node->fd == fd)
// 			return (node);
// 		node = node->next;
// 	}
// 	node = (t_list *)malloc(sizeof(t_list));
// 	if (!node)
// 		return (ft_freelist(*head), NULL);
// 	node->fd = fd;
// 	node->save = 0;
// 	node->next = 0;
// 	return (node);
// }

// void	ft_freelist(t_list *head)
// {
// 	t_list	*tmp;

// 	while (head)
// 	{
// 		ft_free(&head->save);
// 		tmp = head;
// 		head = head->next;
// 		free(tmp);
// 	}
// }
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
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*start;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	start = *lst;
	while (start)
	{
		del(start->content);
		tmp = start;
		start = start->next;
		free(tmp);
	}
	*lst = 0;
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

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			buf[BUFFER_SIZE + 1];
	int				len;
	char			*ret;
	t_list			*node;

	ret = 0;
	len = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	node = ft_findfd(&head, fd);
	if (!node)
		return (0);
	if (node->save && ft_ln_in_save(&node->save, &ret, head))
		return (ret);
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
			return (ft_freelist(head), ft_free(&ret), NULL);
		buf[len] = '\0';
		if (len && ft_ln_in_buf(buf, &node->save, &ret, head))
			break ;
	}
	return (ret);
}
