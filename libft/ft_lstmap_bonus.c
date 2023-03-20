/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:48:43 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/20 17:37:22 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_makenewlst(t_list **lst, int size)
{
	int		i;
	t_list	*new_lst;

	i = 0;
	*lst = ft_lstnew(0);
	if (*lst)
		i++;
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
		if (ft_makenewlst(&new_lst, lst_size) == lst_size)
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
			ft_lstiter(new_lst, del);
	}
	return (new_lst_start);
}
