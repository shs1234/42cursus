/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:03:53 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/29 14:26:44 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	*ran;
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	len = max - min;
	ran = (int *)malloc(sizeof(int) * len);
	if (!ran)
		return (-1);
	while (i < len)
	{
		ran[i] = min;
		min++;
		i++;
	}
	*range = ran;
	return (len);
}

// #include <stdio.h>
// int main(void)
// {
// 	int *ran;
// 	int i = 0;
// 	int min = 1;
// 	int max = 1;
// 	int len;
// 	len = ft_ultimate_range(&ran, 2147483647, -3873);
// 	printf("len : %d\n", len);
// 	while (i < max - min)
// 	{
// 		printf("%d\n", ran[i]);
// 		i++;
// 	}
// }
//  run_test(2147483647, -3873, 0);