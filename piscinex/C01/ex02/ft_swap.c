/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:09:46 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/16 12:13:29 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// #include <stdio.h>
// int main()
// {
// 	int c = 42, d = 0; 
// 	ft_swap(&c, &d);
// 	printf("answer: 0 42\n");
// 	printf("yours : %d %d", c, d);
// 	printf("\n");
// }