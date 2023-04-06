/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:12:54 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/07 03:51:20 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(int *a, t_index *index)
{
	if (index->a_count > 1)
	{
		if (index->a_count == index->a_head + 1)
			ft_swap(&a[index->a_head], &a[0]);
		else
			ft_swap(&a[index->a_head], &a[index->a_head + 1]);
	}
}

void	ft_sb(int *b, t_index *index)
{
	if (index->b_count > 1)
	{
		if (index->b_count == index->b_head + 1)
			ft_swap(&b[index->b_head], &b[0]);
		else
			ft_swap(&b[index->b_head], &b[index->b_head + 1]);
	}
}

void	ft_ss(int *a, int *b, t_index *index)
{
	ft_sa(a, index);
	ft_sb(b, index);
}

void	ft_pa(int *a, t_index *index)
{
}