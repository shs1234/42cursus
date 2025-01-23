/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:01:06 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/31 22:34:36 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_plus(int n1, int n2)
{
	ft_putnbr(n1 + n2);
}

void	ft_minus(int n1, int n2)
{
	ft_putnbr(n1 - n2);
}

void	ft_mul(int n1, int n2)
{
	ft_putnbr(n1 * n2);
}

void	ft_div(int n1, int n2)
{
	if (n2 == 0)
		write(1, "Stop : division by zero", 23);
	else
		ft_putnbr(n1 / n2);
}

void	ft_mod(int n1, int n2)
{
	if (n2 == 0)
		write(1, "Stop : modulo by zero", 21);
	else
		ft_putnbr(n1 % n2);
}
