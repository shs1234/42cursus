/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:26:22 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/29 16:59:56 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*start;
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	start = *lst;
	while (start)
	{
		if (del)
			del(start->content);
		tmp = start;
		start = start->next;
		free(tmp);
	}
	*lst = 0;
}
