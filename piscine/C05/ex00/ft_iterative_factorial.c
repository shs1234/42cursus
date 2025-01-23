/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:24:00 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/23 17:15:35 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	res;

	i = 1;
	res = 1;
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		res *= i;
		i++;
	}
	return (res);
}

// #include <stdio.h>
// int main()
// {
//         printf("Factorial %d = %d\n", -32, ft_iterative_factorial(-32));
//         printf("Factorial %d = %d\n", 0, ft_iterative_factorial(0));
//         printf("Factorial %d = %d\n", 1, ft_iterative_factorial(1));
//         printf("Factorial %d = %d\n", 2, ft_iterative_factorial(2));
//         printf("Factorial %d = %d\n", 12, ft_iterative_factorial(12));
//         printf("Factorial %d = %d\n", 3, ft_iterative_factorial(3));
//         printf("Factorial %d = %d\n", 5, ft_iterative_factorial(5));
//         printf("Factorial %d = %d\n", 6, ft_iterative_factorial(6));
//         printf("Factorial %d = %d\n", 7, ft_iterative_factorial(7));
//         printf("Factorial %d = %d\n", 8, ft_iterative_factorial(8));
//         printf("Factorial %d = %d\n", 9, ft_iterative_factorial(9));
//         printf("Factorial %d = %d\n", 10, ft_iterative_factorial(10));
//         printf("Factorial %d = %d\n", 11, ft_iterative_factorial(11));
// }

// Factorial -32 = 0
// Factorial 0 = 1
// Factorial 1 = 1
// Factorial 2 = 2
// Factorial 12 = 479001600
// Factorial 3 = 6
// Factorial 5 = 120
// Factorial 6 = 720
// Factorial 7 = 5040
// Factorial 8 = 40320
// Factorial 9 = 362880
// Factorial 10 = 3628800
// Factorial 11 = 39916800