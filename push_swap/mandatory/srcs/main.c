/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:37:57 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/06 18:03:31 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_stack_init(int ac, char **av, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	ft_bzero(b, sizeof(t_stack));
	a->head = malloc(sizeof(t_node));
	if (!a->head)
		return (0);
	a->head->n = ft_atoi(av[i]);
	a->head->prev = NULL;
	a->tail = a->head;
	a->count = ac;
	while (++i < ac)
	{
		a->tail->next = malloc(sizeof(t_node));
		if (!a->tail->next)
			return (0);
		a->tail->next->prev = a->tail;
		a->tail = a->tail->next;
		a->tail->next = NULL;
		a->tail->n = ft_atoi(av[i]);
	}
	return (1);
}

static int	ac2(int *ac, char ***av)
{
	if (*ac == 2)
	{
		if (!(*av)[1][0])
			return (1);
		*av = ft_split((*av)[1], ' ', ac);
		if (*ac == 0)
			return (1);
	}
	else
	{
		(*ac)--;
		(*av)++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	t_list	*lst;

	if (ac > 1)
	{
		if (ac2(&ac, &av))
			return (0);
		if (ft_is_valid(ac, av) && ft_stack_init(ac, av, &a, &b))
		{
			lst = 0;
			a.list_head = &lst;
			b.list_head = &lst;
			ft_sorting(&a, &b);
		}
		else
			ft_error();
	}
	return (0);
}
