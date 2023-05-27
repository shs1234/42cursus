/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:13:10 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/28 03:29:00 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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
	int				count;
	int				first_iter;
}					t_stack;

int					ft_isdigit(int c);
int					ft_is_valid(int ac, char **av);
int					ft_strcmp(char *s1, char *s2);

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
char				*ft_strcpy(char *dest, char *src);
void				ft_putstr_fd(char *s, int fd);
void				ft_bzero(void *s, size_t n);

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

char				*get_next_line(int fd);
char				*ft_strjoin(char *s1, const char *s2, int i);
int					ft_strlen(const char *s);
char				*ft_strdup(const char *s1, char *save);
int					ft_has_newline(char *buf);
void				ft_free(char **mem);
int					ft_ln_in_save(char **save, char **ret);
int					ft_ln_in_buf(char *buf, char **save, char **ret);

char				**ft_split(char const *s, char c, int *split_len);

#endif