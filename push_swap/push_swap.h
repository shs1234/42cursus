/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:13:10 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/07 03:44:19 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_index
{
	size_t	a_head;
	size_t	a_tail;
	size_t	a_count;
	size_t	b_head;
	size_t	b_tail;
	size_t	b_count;
	size_t	len;
}			t_index;

int			ft_is_valid(int ac, char **av);
void		ft_sorting(int ac, char **av);
void		ft_swap(int *a, int *b);

#endif