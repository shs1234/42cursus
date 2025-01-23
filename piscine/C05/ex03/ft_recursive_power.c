/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:52:50 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/23 17:33:27 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * ft_recursive_power(nb, power - 1));
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d ^ %d = %d\n", -4217, -1812, ft_recursive_power(-4217, -1812));
// 	printf("%d ^ %d = %d\n", 0, 0, ft_recursive_power(0, 0));
// 	printf("%d ^ %d = %d\n", 3042, 0, ft_recursive_power(3042, 0));
// 	printf("%d ^ %d = %d\n", 3041, 1, ft_recursive_power(3041, 1));
// 	printf("%d ^ %d = %d\n", 1, 2, ft_recursive_power(1, 2));
// 	printf("%d ^ %d = %d\n", 3, 4, ft_recursive_power(3, 4));
// 	printf("%d ^ %d = %d\n", 5, 6, ft_recursive_power(5, 6));
// 	printf("%d ^ %d = %d\n", 7, 7, ft_recursive_power(7, 7));
// 	printf("%d ^ %d = %d\n", 8, 8, ft_recursive_power(8, 8));
// 	printf("%d ^ %d = %d\n", -7, 9, ft_recursive_power(-7, 9));
// 	printf("%d ^ %d = %d\n", -3, 10, ft_recursive_power(-3, 10));
// }

// -4217 ^ -1812 = 0
// 0 ^ 0 = 1
// 3042 ^ 0 = 1
// 3041 ^ 1 = 3041
// 1 ^ 2 = 1
// 3 ^ 4 = 81
// 5 ^ 6 = 15625
// 7 ^ 7 = 823543
// 8 ^ 8 = 16777216
// -7 ^ 9 = -40353607
// -3 ^ 10 = 59049