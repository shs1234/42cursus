/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:33:27 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/07 01:58:56 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_makestack(int ac, char **av, int **stack_a, int **stack_b)
{
	int	i;

	*stack_a = (int *)malloc(sizeof(int) * (ac - 1));
	if (!*stack_a)
		return (0);
	*stack_b = (int *)malloc(sizeof(int) * (ac - 1));
	if (!*stack_a)
		return (free(stack_a), 0);
	i = 0;
	while (i < ac - 1)
	{
		(*stack_a)[i] = ft_atoi(av[i + 1]);
		i++;
	}
	(void)stack_b;
	return (1);
}

int	ft_sorting(int ac, char **av)
{
	int		*stack_a;
	int		*stack_b;
	t_index	*index;

	if (!ft_makestack(ac, av, &stack_a, &stack_b))
		return (0);
	index = (t_index *)malloc(sizeof(t_index));
	if (!index)
		return (0);
	index->a_head = 0;
	index->b_head = 0;
	index->a_tail = ac - 2;
	index->b_tail = ac - 2;
	printf("%d %d %d %d\n", index->a_head, index->b_head, index->a_tail,
			index->b_tail);
	return (1);
}
