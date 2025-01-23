/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:45:11 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/16 13:58:54 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	flag;

	flag = 1;
	while (flag)
	{
		i = 0;
		flag = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				flag = 1;
			}
			i++;
		}
	}
}

// #include <stdio.h>
// int main()
// {
// 	int arr08[] = {7, 1, 4, 5, 9, 0, 6, 8, 3, 2};
// 	ft_sort_int_tab(arr08, 10);
// 	int i8 = 0;
// 	printf("answer = 0 1 2 3 4 5 6 7 8 9 \n");
// 	printf("yours : ");
// 	while (i8 <= 9)
// 	{
// 		printf("%d ", arr08[i8]);
// 		i8++;
// 	}
// 	printf("\n");
// }
