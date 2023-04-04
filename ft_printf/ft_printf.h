/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:37:47 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/04 23:43:27 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_printarg(char c, va_list ap);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putuint_fd(unsigned int n, int fd);
int		ft_print_hex_upper(unsigned int n);
int		ft_print_hex_lower(unsigned int n);
int		ft_print_addr(void *addr);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

#endif