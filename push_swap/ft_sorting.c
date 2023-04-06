/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:33:27 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/07 03:25:39 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_stack_init(int ac, char **av, int **a, int **b, t_index **index)
{
	size_t	i;

	*a = (int *)malloc(sizeof(int) * (ac - 1));
	*b = (int *)malloc(sizeof(int) * (ac - 1));
	*index = (t_index *)malloc(sizeof(t_index));
	if (!*a || !*b || !*index)
		exit(1);
	i = 0;
	while (i < ac - 1)
	{
		(*a)[i] = ft_atoi(av[i + 1]);
		i++;
	}
	(*index)->a_head = 0;
	(*index)->a_tail = ac - 2;
	(*index)->a_count = ac - 1;
	(*index)->b_head = 0;
	(*index)->b_tail = ac - 2;
	(*index)->b_count = 0;
	(*index)->len = ac - 1;
}

void	ft_sorting(int ac, char **av)
{
	int		*a;
	int		*b;
	t_index	*index;

	ft_stack_init(ac, av, &a, &b, &index);
	// printf("%d %d %d %d\n", index->a_head, index->b_head, index->a_tail,
	// 		index->b_tail);
}
