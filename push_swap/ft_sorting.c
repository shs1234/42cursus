/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:33:27 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/19 14:54:25 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_init(int ac, char **av, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	a->head = malloc(sizeof(t_node));
	if (!a->head)
		ft_error();
	a->head->n = ft_atoi(av[i]);
	a->head->prev = NULL;
	a->tail = a->head;
	a->count = 1;
	a->first_iter = 1;
	b->head = NULL;
	b->tail = NULL;
	b->count = 0;
	while (++i < ac)
	{
		a->tail->next = malloc(sizeof(t_node));
		if (!a->tail->next)
			ft_error();
		a->tail->next->prev = a->tail;
		a->tail = a->tail->next;
		a->tail->next = NULL;
		a->tail->n = ft_atoi(av[i]);
		a->count++;
	}
}

static void	ft_print_inst(t_stack *a)
{
	while (*a->list_head)
	{
		ft_putstr_fd((char *)(*a->list_head)->content, STDOUT_FILENO);
		*a->list_head = (*a->list_head)->next;
	}
}

static void	ft_ac3(t_stack *a)
{
	int	i;

	i = ft_whereisbig(a->head, 3);
	if (i == 2)
		ft_rra(a);
	else if (i == 1)
		ft_ra(a);
	if (a->head->n > a->head->next->n)
		ft_sa(a);
}

static void	ft_ac5(t_stack *a, t_stack *b)
{
	int	i;
	int	mid;

	i = 0;
	mid = ft_3rd_5(a->head);
	while (i < 2)
	{
		if (a->head->n < mid)
		{
			ft_pb(a, b);
			i++;
		}
		else
			ft_ra(a);
	}
	ft_ac3(a);
	ft_pa(a, b);
	ft_pa(a, b);
	if (a->head->n > a->head->next->n)
		ft_sa(a);
}

void	ft_sorting(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*lst;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
		ft_error();
	lst = NULL;
	a->list_head = &lst;
	b->list_head = &lst;
	ft_stack_init(ac, av, a, b);
	if (ac == 3)
		ft_ac3(a);
	else if (ac == 5)
		ft_ac5(a, b);
	else
		ft_atob(a, b, ac);
	ft_print_inst(a);
}
