/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:12:54 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/17 01:09:35 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a)
{
	t_node	*temp;

	if (a->count > 1)
	{
		temp = a->head;
		a->head = a->head->next;
		a->head->prev = 0;
		a->tail->next = temp;
		temp->prev = a->tail;
		temp->next = 0;
		a->tail = temp;
		ft_lstadd_back(a->list_head, ft_lstnew("ra\n"));
	}
}

void	ft_rb(t_stack *b)
{
	t_node	*temp;

	if (b->count > 1)
	{
		temp = b->head;
		b->head = b->head->next;
		b->head->prev = 0;
		b->tail->next = temp;
		temp->prev = b->tail;
		temp->next = 0;
		b->tail = temp;
		ft_lstadd_back(b->list_head, ft_lstnew("rb\n"));
	}
}
void	ft_rr(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (a->count > 1)
	{
		temp = a->head;
		a->head = a->head->next;
		a->head->prev = 0;
		a->tail->next = temp;
		temp->prev = a->tail;
		temp->next = 0;
		a->tail = temp;
	}
	if (b->count > 1)
	{
		temp = b->head;
		b->head = b->head->next;
		b->head->prev = 0;
		b->tail->next = temp;
		temp->prev = b->tail;
		temp->next = 0;
		b->tail = temp;
	}
	if (a->count > 1 || b->count > 1)
		ft_lstadd_back(a->list_head, ft_lstnew("rr\n"));
}
