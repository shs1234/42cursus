/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:33:27 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/09 04:08:50 by hoseoson         ###   ########.fr       */
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

void	ft_merge(t_stack *a, t_stack *b, int end)
{
	int		i;
	int		j;
	int		m;
	t_node	*div_i;
	t_node	*div_j;

	// printf("----------------------\n%d : ", end);
	if (end == 1)
	{
		ft_ra(a);
		return ;
	}
	else if (end == 2)
	{
		if (a->head->n < a->head->next->n)
		{
			ft_ra(a);
			ft_ra(a);
		}
		else
		{
			ft_sa(a);
			ft_ra(a);
			ft_ra(a);
		}
		return ;
	}
	div_i = a->head;
	div_j = a->head;
	i = 0;
	end--;
	m = (i + end) / 2;
	j = m + 1;
	while (i < j)
	{
		div_j = div_j->next;
		i++;
	}
	i = 0;
	while (i <= m)
	{
		if (a->head->n < div_j->n)
			ft_ra(a);
		else
		{
			ft_pb(a, b);
			ft_rb(b);
		}
		i++;
	}
	while (j <= end)
	{
		if (b->head)
		{
			if (a->head->n < b->head->n)
			{
				ft_ra(a);
				j++;
			}
			else
			{
				ft_pa(a, b);
				ft_ra(a);
			}
		}
		else
		{
			ft_ra(a);
			j++;
		}
	}
	while (b->head)
	{
		ft_pa(a, b);
		ft_ra(a);
	}
	// ft_print_stack(a, b);
}

void	ft_divide(t_stack *a, t_stack *b, int n)
{
	int	i;
	int	j;
	int	tab[20000];

	i = 0;
	j = 0;
	tab[i++] = n;
	while (i < 20000)
	{
		if (tab[j] / 2 == 0)
			break ;
		tab[i++] = tab[j] / 2;
		tab[i++] = tab[j] - tab[j] / 2;
		j++;
	}
	while (--i >= 0)
		ft_merge(a, b, tab[i]);
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
	ft_divide(a, b, ac - 1);
	// ft_print_stack(a, b);
}
