/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:13:42 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/16 12:22:55 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// #include <stdio.h>
// int main()
// {
// 	int a3 = 6, b3 = 3;
// 	int c3, d3;
// 	int *p31 = &c3;
// 	int *p32 = &d3;
// 	ft_div_mod(a3, b3, p31, p32);
// 	printf("div:%d\nmod:%d\n", c3, d3);
// }