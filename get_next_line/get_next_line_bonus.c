/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:08:58 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/02 20:16:50 by hoseoson         ###   ########.fr       */
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

// void	ft_lstfree(t_list **lst)
// {
// 	t_list	*start;
// 	t_list	*tmp;

// 	if (*lst)
// 	{
// 		start = (*lst)->next;
// 		while (start)
// 		{
// 			ft_free(&start->save);
// 			tmp = start;
// 			start = start->next;
// 			free(tmp);
// 		}
// 		start = (*lst)->prev;
// 		while (start)
// 		{
// 			ft_free(&start->save);
// 			tmp = start;
// 			start = start->prev;
// 			free(tmp);
// 		}
// 		ft_free(&(*lst)->save);
// 		free(*lst);
// 		*lst = 0;
// 	}
// }

// t_list	*ft_lst_fd(int fd, t_list *lst)
// {
// 	t_list	*node;

// 	if (!lst)
// 	{
// 		lst = (t_list *)malloc(sizeof(t_list));
// 		if (!lst)
// 			return (NULL);
// 		lst->fd = fd;
// 		lst->next = NULL;
// 		lst->prev = NULL;
// 		lst->save = NULL;
// 		return (lst);
// 	}
// 	node = lst->next;
// 	while (node)
// 	{
// 		if (node->fd == fd)
// 			return (node);
// 		node = node->next;
// 	}
// 	node = lst->prev;
// 	while (node)
// 	{
// 		if (node->fd == fd)
// 			return (node);
// 		node = node->prev;
// 	}
// 	lst->prev = (t_list *)malloc(sizeof(t_list)); //실패시 리스트 삭제
// 	if (!lst->prev)
// 		return (ft_lstfree(&lst), NULL);
// 	lst->prev->fd = fd;
// 	lst->prev->save = 0;
// 	lst->prev->prev = 0;
// 	lst->prev->next = lst;
// 	return (lst->prev);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*save;
// 	char		buf[BUFFER_SIZE + 1];
// 	int			len;
// 	char		*ret;

// 	ret = 0;
// 	len = 1;
// 	if (fd < 0 || BUFFER_SIZE < 1)
// 		return (NULL);
// 	if (save && ft_ln_in_save(&save, &ret))
// 		return (ret);
// 	while (len)
// 	{
// 		len = read(fd, buf, BUFFER_SIZE);
// 		if (len == -1)
// 			return (ft_free(&save), ft_free(&ret), NULL);
// 		buf[len] = '\0';
// 		if (len && ft_ln_in_buf(buf, &save, &ret))
// 			break ;
// 	}
// 	return (ret);
// }

void	ft_freelst(t_list *lst)
{
	int	i;

	i = 0;
	while (i < FD_MAX + 1)
	{
		ft_free(&lst[i].save);
		i++;
	}
}

char	*get_next_line(int fd)
{
	static t_list	lst[FD_MAX + 1];
	char			buf[BUFFER_SIZE + 1];
	int				len;
	char			*ret;

	ret = 0;
	len = 1;
	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (lst[fd].save && ft_ln_in_save(&lst[fd].save, &ret))
		return (ret);
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
			return (ft_freelst(lst), ft_free(&ret), NULL);
		buf[len] = '\0';
		if (len && ft_ln_in_buf(buf, &lst[fd].save, &ret))
			break ;
	}
	return (ret);
}
