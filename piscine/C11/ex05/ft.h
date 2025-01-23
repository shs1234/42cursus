/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:05:07 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/31 18:02:08 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

void	ft_putchar(char c);
void	ft_except(int nb);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
void	ft_plus(int n1, int n2);
void	ft_minus(int n1, int n2);
void	ft_mul(int n1, int n2);
void	ft_div(int n1, int n2);
void	ft_mod(int n1, int n2);
void	ft_set_opers(void (**f)(int, int));

#endif