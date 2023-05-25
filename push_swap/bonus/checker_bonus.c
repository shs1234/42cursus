/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 06:21:54 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/26 03:52:19 by hoseoson         ###   ########.fr       */
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

static void	ft_checker(int ac, char **av)
{
	char	*inst;
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
	while (1)
	{
		inst = get_next_line(STDIN_FILENO);
		if (!inst)
			break ;
		ft_execute(inst, a, b);
	}
	if (ft_issorted(a->head, a->count) && b->count == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		if (ac == 2)
		{
			av = ft_split(av[1], ' ', &ac);
			if (ac == 1)
				exit(0);
		}
		else
		{
			ac--;
			av++;
		}
		if (ft_is_valid(ac, av))
			ft_checker(ac, av);
		else
			ft_error();
	}
	exit(0);
}
