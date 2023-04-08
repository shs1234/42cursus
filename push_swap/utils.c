/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 03:40:41 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/09 02:48:29 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(1);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_print_stack(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = a->head;
	printf("a : ");
	while (node)
	{
		printf("%d ", node->n);
		node = node->next;
	}
	printf("\n");
	printf("b : ");
	node = b->head;
	while (node)
	{
		printf("%d ", node->n);
		node = node->next;
	}
	printf("\n");
}
