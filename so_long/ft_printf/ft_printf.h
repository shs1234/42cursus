/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:37:47 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/22 03:49:27 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar_ret(char c);
int		ft_putstr_ret(char *s);
int		ft_putnbr_ret(int n);
int		ft_putuint_ret(unsigned int n);
int		ft_print_hex_upper(unsigned int n);
int		ft_print_hex_lower(unsigned int n);
int		ft_putaddr(void *addr);
char	*ft_strchr(const char *s, int c);

#endif