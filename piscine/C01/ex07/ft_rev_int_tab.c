/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:39:29 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/16 13:44:28 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size / 2)
	{
		ft_swap(&tab[i], &tab[size - 1 - i]);
		i++;
	}
}

// #include <stdio.h>
// int main()
// {
// 	int arr07[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// 	ft_rev_int_tab(arr07, 10);
// 	int i7 = 0;
// 	printf("answer : 9 8 7 6 5 4 3 2 1 0\n");
// 	printf("yours : ");
// 	while (i7 <= 9)
// 	{
// 		printf("%d ", arr07[i7]);
// 		i7++;
// 	}
// 	printf("\n");
// }