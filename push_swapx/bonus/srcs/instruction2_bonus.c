/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:12:54 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/28 03:19:31 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}
