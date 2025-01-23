/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:13:10 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/07 00:18:26 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				n;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	t_list			**list_head;
	int				count;
}					t_stack;

int					ft_is_valid(int ac, char **av);

void				ft_sorting(t_stack *a, t_stack *b);
void				ft_atob(t_stack *a, t_stack *b, int n);
void				ft_atob_3(t_stack *a, t_stack *b);
void				ft_btoa(t_stack *a, t_stack *b, int n);
void				ft_btoa_2(t_stack *a, t_stack *b);

void				ft_swap(int *a, int *b);
void				ft_sort_int_tab(int *tab, int size);
void				ft_error(void);
void				ft_pivot(t_stack *stack, int n, int *pivot);
void				ft_rrab(t_stack *a, t_stack *b, int *count);
int					ft_3rd_5(t_node *node);
void				ft_putstr_fd(char *s, int fd);
int					ft_isdigit(int c);
void				ft_bzero(void *s, size_t n);
int					ft_strlen(const char *s);
int					ft_numlen(long long n);

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

int					ft_whereisbig(t_node *node, int n);
int					ft_issorted(t_node *node, int n);
int					ft_issorted_rev(t_stack *a, t_stack *b, int n);

int					ft_atoi(const char *str);

void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(char *content);

char				**ft_split(char const *s, char c, int *split_len);

#endif