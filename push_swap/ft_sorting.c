/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:33:27 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/13 07:15:42 by hoseoson         ###   ########.fr       */
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

void	ft_pivot(t_stack *stack, int n, int *pivot)
{
	t_node	*node;
	int		i;
	int		*tab;

	node = stack->head;
	tab = (int *)malloc(sizeof(int) * n);
	if (!tab)
		ft_error();
	i = 0;
	while (node && i < n)
	{
		// printf("----------%d--%d ", n, node->n);
		tab[i] = node->n;
		node = node->next;
		i++;
	}
	ft_sort_int_tab(tab, n);
	pivot[0] = tab[n / 3];
	pivot[1] = tab[(n / 3) * 2];
	free(tab);
}

void	ft_atob(t_stack *a, t_stack *b, int n, int stack, char *pos)
{
	int	pivot[2];
	int	i;
	int	count_middle;
	int	count_big;

	count_middle = 0;
	count_big = 0;
	i = 0;
	if (n)
		ft_pivot(a, n, pivot);
	// printf("----%s-----[atob] stack : %d n : %d pivot[0] :
	// %d pivot[1] :%d\n",
	// 		pos,
	// 		stack,
	// 		n,
	// 		pivot[0],
	// 		pivot[1]);
	// ft_print_stack(a, b);
	(void)pos;
	if (n <= 3)
	{
		if (n == 3)
		{
			if (a->head->next->next->n > a->head->next->n
				&& a->head->next->next->n > a->head->n)
			{
				ft_pb(a, b);
				ft_pb(a, b);
			}
			else if (a->head->next->n > a->head->next->next->n
					&& a->head->next->n > a->head->n)
			{
				ft_pb(a, b);
				ft_ra(a);
				ft_pb(a, b);
				ft_rra(a);
			}
			else if (a->head->n > a->head->next->next->n
					&& a->head->n > a->head->next->n)
			{
				ft_ra(a);
				ft_pb(a, b);
				ft_pb(a, b);
				ft_rra(a);
			}
			if (b->head->n < b->head->next->n)
				ft_sb(b);
		}
		else if (n == 2)
		{
			if (a->head->n > a->head->next->n)
				ft_sa(a);
			ft_pb(a, b);
		}
		ft_pb(a, b);
		// ft_print_stack(a, b);
		return ;
	}
	while (i < n)
	{
		// printf("n : [%d]\n", a->head->n);
		if (a->head->n >= pivot[1])
		{
			ft_ra(a);
			count_big++;
		}
		else
		{
			ft_pb(a, b);
			if (b->head->n >= pivot[0])
			{
				ft_rb(b);
				count_middle++;
			}
		}
		i++;
		// ft_print_stack(a, b);
	}
	// printf("\n");
	i = 0;
	// printf("------count_big : %d  count_middle : %d-------\n", count_big,
	// 		count_middle);
	while (i < count_big && i < count_middle)
	{
		ft_rrr(a, b);
		// ft_print_stack(a, b);
		i++;
	}
	while (i < count_big)
	{
		ft_rra(a);
		// ft_print_stack(a, b);
		i++;
	}
	while (i < count_middle)
	{
		ft_rrb(b);
		// ft_print_stack(a, b);
		i++;
	}
	ft_atob(a, b, count_big, stack + 1, "big");
	ft_btoa(a, b, count_big, stack + 1, "big");
	ft_btoa(a, b, count_middle, stack + 1, "mid");
	ft_btoa(a, b, n - count_big - count_middle, stack + 1, "smal");
}

void	ft_btoa(t_stack *a, t_stack *b, int n, int stack, char *pos)
{
	int	pivot[2];
	int	i;
	int	count_small;
	int	count_middle;

	if (b->head == NULL)
		exit(0);
	count_small = 0;
	count_middle = 0;
	i = 0;
	i = 0;
	(void)pos;
	if (n)
		ft_pivot(b, n, pivot);
	// printf("----%s------[btoa] stack : %d n : %d pivot[0] :
	// % d pivot[1] : % d\n ",
	// 		pos,
	// 		stack,
	// 		n,
	// 		pivot[0],
	// 		pivot[1]);
	// ft_print_stack(a, b);
	if (n <= 3)
	{
		if (n == 3)
		{
			if (b->head->next->next->n > b->head->next->n
				&& b->head->next->next->n > b->head->n)
			{
				ft_rb(b);
				ft_rb(b);
				ft_pa(a, b);
				ft_rrb(b);
				ft_rrb(b);
			}
			else if (b->head->next->n > b->head->next->next->n
					&& b->head->next->n > b->head->n)
			{
				ft_rb(b);
				ft_pa(a, b);
				ft_rrb(b);
			}
			else if (b->head->n > b->head->next->next->n
					&& b->head->n > b->head->next->n)
			{
				ft_pa(a, b);
			}
			if (b->head->n < b->head->next->n)
				ft_sb(b);
			ft_pa(a, b);
		}
		else if (n == 2)
		{
			if (b->head->n < b->head->next->n)
				ft_sb(b);
			ft_pa(a, b);
		}
		ft_pa(a, b);
		// ft_print_stack(a, b);
		return ;
	}
	while (i < n)
	{
		if (b->head == NULL)
			exit(0);
		if (b->head->n < pivot[0])
		{
			ft_rb(b);
			count_small++;
		}
		else
		{
			ft_pa(a, b);
			if (a->head->n < pivot[1])
			{
				ft_ra(a);
				count_middle++;
			}
		}
		i++;
		// ft_print_stack(a, b);
	}
	// printf("\n");
	i = 0;
	ft_atob(a, b, n - count_small - count_middle, stack + 1, "big");
	ft_btoa(a, b, n - count_small - count_middle, stack + 1, "big");
	// printf("------count_small : %d  count_middle : %d-------\n", count_small,
	// 		count_middle);
	while (i < count_small && i < count_middle)
	{
		ft_rrr(a, b);
		// ft_print_stack(a, b);
		i++;
	}
	while (i < count_small)
	{
		ft_rrb(b);
		// ft_print_stack(a, b);
		i++;
	}
	while (i < count_middle)
	{
		ft_rra(a);
		// ft_print_stack(a, b);
		i++;
	}
	ft_atob(a, b, count_middle, stack + 1, "mid");
	ft_btoa(a, b, count_small, stack + 1, "smal");
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
	ft_atob(a, b, ac - 1, 1, "start");
	// ft_print_stack(a, b);
}
