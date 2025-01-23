/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:34:34 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/23 17:27:19 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

// #include <stdio.h>
// int main()
// {
// 	printf("Factorial %d = %d\n", -52, ft_recursive_factorial(-52));
// 	printf("Factorial %d = %d\n", 0, ft_recursive_factorial(0));
// 	printf("Factorial %d = %d\n", 1, ft_recursive_factorial(1));
// 	printf("Factorial %d = %d\n", 2, ft_recursive_factorial(2));
// 	printf("Factorial %d = %d\n", 12, ft_recursive_factorial(12));
// 	printf("Factorial %d = %d\n", 3, ft_recursive_factorial(3));
// 	printf("Factorial %d = %d\n", 4, ft_recursive_factorial(4));
// 	printf("Factorial %d = %d\n", 5, ft_recursive_factorial(5));
// 	printf("Factorial %d = %d\n", 6, ft_recursive_factorial(6));
// 	printf("Factorial %d = %d\n", 8, ft_recursive_factorial(8));
// 	printf("Factorial %d = %d\n", 9, ft_recursive_factorial(9));
// 	printf("Factorial %d = %d\n", 10, ft_recursive_factorial(10));
// 	printf("Factorial %d = %d\n", 11, ft_recursive_factorial(11));
// }

// Factorial -52 = 0
// Factorial 0 = 1
// Factorial 1 = 1
// Factorial 2 = 2
// Factorial 12 = 479001600
// Factorial 3 = 6
// Factorial 4 = 24
// Factorial 5 = 120
// Factorial 6 = 720
// Factorial 8 = 40320
// Factorial 9 = 362880
// Factorial 10 = 3628800
// Factorial 11 = 39916800