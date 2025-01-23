/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:12:54 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/26 04:10:42 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a)
{
	if (a->count > 1)
	{
		ft_swap(&a->head->n, &a->head->next->n);
		ft_lstadd_back(a->list_head, ft_lstnew("sa\n"));
	}
}

void	ft_sb(t_stack *b)
{
	if (b->count > 1)
	{
		ft_swap(&b->head->n, &b->head->next->n);
		ft_lstadd_back(b->list_head, ft_lstnew("sb\n"));
	}
}

void	ft_ss(t_stack *a, t_stack *b)
{
	if (a->count > 1)
		ft_swap(&a->head->n, &a->head->next->n);
	if (b->count > 1)
		ft_swap(&b->head->n, &b->head->next->n);
	if (a->count > 1 || b->count > 1)
		ft_lstadd_back(a->list_head, ft_lstnew("ss\n"));
}

void	ft_pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (b->count > 0)
	{
		temp = b->head;
		if (b->head->next)
		{
			b->head = b->head->next;
			b->head->prev = NULL;
		}
		else
		{
			b->head = NULL;
			b->tail = NULL;
		}
		temp->next = a->head;
		a->head = temp;
		if (a->head->next)
			a->head->next->prev = temp;
		else
			a->tail = a->head;
		a->count++;
		b->count--;
		ft_lstadd_back(a->list_head, ft_lstnew("pa\n"));
	}
}

void	ft_pb(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (a->count > 0)
	{
		temp = a->head;
		if (a->head->next)
		{
			a->head = a->head->next;
			a->head->prev = NULL;
		}
		else
		{
			a->head = NULL;
			a->tail = NULL;
		}
		temp->next = b->head;
		b->head = temp;
		if (b->head->next)
			b->head->next->prev = temp;
		else
			b->tail = b->head;
		b->count++;
		a->count--;
		ft_lstadd_back(a->list_head, ft_lstnew("pb\n"));
	}
}
