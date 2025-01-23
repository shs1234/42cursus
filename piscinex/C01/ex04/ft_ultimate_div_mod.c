/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:23:09 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/16 13:57:22 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

// #include <stdio.h>
// int main()
// {
// 	int c4 = 7, d4 = 2;
// 	int *p_c4 = &c4;
// 	int *p_d4 = &d4;
// 	ft_ultimate_div_mod(p_c4, p_d4);
// 	printf("%d %d\n", c4, d4);
// }