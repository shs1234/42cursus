/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:16:22 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/13 19:10:26 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_ret(char *s)
{
	int	len;

	if (!s)
		return (ft_putstr_ret("(null)"));
	len = 0;
	while (*s)
	{
		if (ft_putchar_ret(*s) == -1)
			return (-1);
		len++;
		s++;
	}
	return (len);
}
