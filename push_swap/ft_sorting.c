/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:33:27 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/07 20:31:18 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_stack_init(int ac, char **av, t_stack *a, t_stack *b)
{
	int	i;

	i = 1;
	a->head = (t_node *)malloc(sizeof(t_node));
	if (!a->head)
		ft_error();
	a->head->n = ft_atoi(av[i]);
	a->head->prev = NULL;
	a->tail = a->head;
	a->count = 1;
	b->head = NULL;
	b->tail = NULL;
	b->count = 0;
	while (++i < ac)
	{
		a->tail->next = (t_node *)malloc(sizeof(t_node));
		if (!a->tail->next)
			ft_error();
		a->tail->next->prev = a->tail;
		a->tail = a->tail->next;
		a->tail->next = NULL;
		a->tail->n = ft_atoi(av[i]);
		a->count++;
	}
}

void	ft_sorting(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!a || !b)
		ft_error();
	ft_stack_init(ac, av, a, b);
	// ft_print_stack(a, b);
	// ft_pb(a, b);
	// ft_pb(a, b);
	// ft_pb(a, b);
	// ft_print_stack(a, b);
	// ft_ra(a);
	// ft_print_stack(a, b);
	// ft_rb(b);
	// ft_print_stack(a, b);
	// ft_rr(a, b);
	// ft_print_stack(a, b);
	// ft_rra(a);
	// ft_print_stack(a, b);
	// ft_rra(a);
	// ft_print_stack(a, b);
	// ft_rrb(b);
	// ft_print_stack(a, b);
	// ft_rrr(a, b);
	// ft_print_stack(a, b);
}
