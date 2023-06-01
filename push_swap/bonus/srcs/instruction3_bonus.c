/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:12:54 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/28 03:19:47 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}
