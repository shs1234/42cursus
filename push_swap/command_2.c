/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:12:54 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/09 02:46:26 by hoseoson         ###   ########.fr       */
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
		write(1, "ra\n", 3);
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
		write(1, "rb\n", 3);
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
		write(1, "rr\n", 3);
}
