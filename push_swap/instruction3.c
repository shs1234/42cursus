/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:12:54 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/26 04:10:46 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a)
{
	t_node	*temp;

	if (a->count > 1)
	{
		temp = a->tail;
		a->tail = a->tail->prev;
		a->tail->next = 0;
		a->head->prev = temp;
		temp->next = a->head;
		temp->prev = 0;
		a->head = temp;
		ft_lstadd_back(a->list_head, ft_lstnew("rra\n"));
	}
}

void	ft_rrb(t_stack *b)
{
	t_node	*temp;

	if (b->count > 1)
	{
		temp = b->tail;
		b->tail = b->tail->prev;
		b->tail->next = 0;
		b->head->prev = temp;
		temp->next = b->head;
		temp->prev = 0;
		b->head = temp;
		ft_lstadd_back(b->list_head, ft_lstnew("rrb\n"));
	}
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (a->count > 1)
	{
		temp = a->tail;
		a->tail = a->tail->prev;
		a->tail->next = 0;
		a->head->prev = temp;
		temp->next = a->head;
		temp->prev = 0;
		a->head = temp;
	}
	if (b->count > 1)
	{
		temp = b->tail;
		b->tail = b->tail->prev;
		b->tail->next = 0;
		b->head->prev = temp;
		temp->next = b->head;
		temp->prev = 0;
		b->head = temp;
	}
	if (a->count > 1 || b->count > 1)
		ft_lstadd_back(a->list_head, ft_lstnew("rrr\n"));
}
