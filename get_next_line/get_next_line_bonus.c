/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:08:58 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/02 11:49:30 by hoseoson         ###   ########.fr       */
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

void	ft_lstfree(t_list **lst)
{
	t_list	*start;
	t_list	*tmp;
	t_list	*start;
	t_list	*tmp;

	if (*lst)
	{
		start = (*lst)->next;
		while (start)
		{
			ft_free(&start->save);
			tmp = start;
			start = start->next;
			free(tmp);
		}
		start = (*lst)->prev;
		while (start)
		{
			ft_free(&start->save);
			tmp = start;
			start = start->prev;
			free(tmp);
		}
		ft_free(&(*lst)->save);
		free(*lst);
		*lst = 0;
	}
	if (!lst)
		return ;
	start = *lst;
	while (start)
	{
		free(start->content);
		tmp = start;
		start = start->next;
		free(tmp);
	}
	*lst = 0;
}

t_list	*ft_lst_fd(int fd, t_list *lst)
{
	if (!lst)
	{
		lst = (t_list *)malloc(sizeof(t_list));
		if (!lst)
			return (NULL);
		lst->fd = fd;
		lst->next = NULL;
		lst->prev = NULL;
		lst->save = NULL;
		return (lst);
	}
	while (lst->next)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	while (lst->prev)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->prev;
	}
	lst->prev = (t_list *)malloc(sizeof(t_list)); //실패시 리스트 삭제
	if (!lst->prev)
		return (ft_lstfree(lst), NULL);
	lst->prev->fd = fd;
	lst->prev->save = 0;
	lst->prev->prev = 0;
	lst->prev->next = lst;
	return (lst->prev);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			buf[BUFFER_SIZE + 1];
	int				len;
	char			*ret;

	ret = 0;
	len = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (ft_lstfree(&lst), NULL);
	lst = ft_lst_fd(fd, lst);
	if (lst->save && ft_ln_in_save(&lst->save, &ret))
		return (ret);
	while (len)
	{
		len = read(lst->fd, buf, BUFFER_SIZE);
		if (len == -1)
			return (ft_lstfree(&lst), ft_free(&ret), NULL);
		buf[len] = '\0';
		if (len && ft_ln_in_buf(buf, &lst->save, &ret))
			break ;
	}
	return (ret);
}
