/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:13:10 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/07 20:33:27 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				n;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	size_t			count;
}					t_stack;

int					ft_is_valid(int ac, char **av);

void				ft_sorting(int ac, char **av);

void				ft_swap(int *a, int *b);
void				ft_error(void);
void				ft_print_stack(t_stack *a, t_stack *b);

void				ft_sa(t_stack *a);
void				ft_sb(t_stack *b);
void				ft_ss(t_stack *a, t_stack *b);
void				ft_pa(t_stack *a, t_stack *b);
void				ft_pb(t_stack *a, t_stack *b);

void				ft_ra(t_stack *a);
void				ft_rb(t_stack *b);
void				ft_rr(t_stack *a, t_stack *b);

void				ft_rra(t_stack *a);
void				ft_rrb(t_stack *b);
void				ft_rrr(t_stack *a, t_stack *b);

#endif
