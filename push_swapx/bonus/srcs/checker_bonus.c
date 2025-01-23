/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 06:21:54 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/06 18:12:07 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_execute(char *inst, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(inst, "sa\n"))
		ft_sa(a);
	else if (!ft_strcmp(inst, "sb\n"))
		ft_sb(b);
	else if (!ft_strcmp(inst, "ss\n"))
		ft_ss(a, b);
	else if (!ft_strcmp(inst, "pa\n"))
		ft_pa(a, b);
	else if (!ft_strcmp(inst, "pb\n"))
		ft_pb(a, b);
	else if (!ft_strcmp(inst, "ra\n"))
		ft_ra(a);
	else if (!ft_strcmp(inst, "rb\n"))
		ft_rb(b);
	else if (!ft_strcmp(inst, "rr\n"))
		ft_rr(a, b);
	else if (!ft_strcmp(inst, "rra\n"))
		ft_rra(a);
	else if (!ft_strcmp(inst, "rrb\n"))
		ft_rrb(b);
	else if (!ft_strcmp(inst, "rrr\n"))
		ft_rrr(a, b);
	else
		ft_error();
}

static void	ft_checker(t_stack *a, t_stack *b)
{
	char	*inst;

	while (1)
	{
		inst = get_next_line(STDIN_FILENO);
		if (!inst)
			break ;
		ft_execute(inst, a, b);
		free(inst);
	}
	if (ft_issorted(a->head, a->count) && b->count == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

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
	a->count = 1;
	while (++i < ac)
	{
		a->tail->next = malloc(sizeof(t_node));
		if (!a->tail->next)
			return (0);
		a->tail->next->prev = a->tail;
		a->tail = a->tail->next;
		a->tail->next = NULL;
		a->tail->n = ft_atoi(av[i]);
		a->count++;
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

	if (ac > 1)
	{
		if (ac2(&ac, &av))
			return (0);
		if (ft_is_valid(ac, av) && ft_stack_init(ac, av, &a, &b))
			ft_checker(&a, &b);
		else
			ft_error();
	}
	return (0);
}
