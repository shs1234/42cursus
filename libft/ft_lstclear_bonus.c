/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:26:22 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/20 21:46:08 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
