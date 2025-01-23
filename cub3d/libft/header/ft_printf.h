/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:22:53 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/13 19:01:56 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_args {
	struct s_args	*next;
	int				flag_size;
	int				width_size;
	int				width_cnt;
	int				prec_size;
	int				prec_cnt;
	int				arg_size;
	int				one_arg_total_size;
	int				left;
	int				zero;
	int				minus;
	int				field_len;
	char			flag;
	char			spec;
}	t_args;

// ft_take_info.c
void	take_info(va_list *ap, const char *format, t_args **lst, int *pc_size);

// ft_checkers.c
char	chk_spec(const char *format);
int		chk_field(char c);
void	set_arg_total_len(const char **format, t_args *lst);

// ft_field_counters.c
void	count_flag(const char *format, t_args *lst);
void	count_prec(const char **format, t_args *lst);
void	count_width(const char **format, t_args *lst);
void	count_arg(va_list *ap, t_args *lst);

// ft_arg_counters.c
int		count_str(char *str, t_args *lst);
int		count_int(int n, t_args *lst);
int		count_uint(unsigned int n, t_args *lst);
int		count_hex(unsigned long n, t_args *lst);

// ft_input.c
void	input_pc(char *pc, va_list *ap, const char *format, t_args *lst);

// ft_puters.c
void	input_str(char *pc, char *str, t_args *lst);
void	input_hex(char *pc, unsigned long num, char spec);
void	input_int(char *pc, int num);
void	input_num_base(char *pc, unsigned long num, char *base, int base_len);

size_t	ft_strlen(const char *s);

#endif
