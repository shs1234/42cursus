/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:48:43 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/17 19:13:14 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_makelst_size(t_list **lst, int size)
{
	int		i;
	t_list	*new_lst;

	i = 1;
	*lst = ft_lstnew(0);
	while (i < size)
	{
		new_lst = ft_lstnew(0);
		if (new_lst)
			ft_lstadd_front(lst, new_lst);
		else
			return (i);
		i++;
	}
	return (i);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		lst_size;
	t_list	*new_lst;
	t_list	*new_lst_start;

	new_lst_start = 0;
	lst_size = ft_lstsize(lst);
	if (lst_size)
	{
		if (ft_makelst_size(&new_lst, lst_size) == lst_size)
		{
			new_lst_start = new_lst;
			while (new_lst)
			{
				new_lst->content = f(lst->content);
				new_lst = new_lst->next;
				lst = lst->next;
			}
		}
		else
		{
			ft_lstiter(new_lst, del);
			return (0);
		}
	}
	return (new_lst_start);
}
