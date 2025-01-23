/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:33:07 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/29 14:35:05 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		len;
	int		*ran;
	int		i;

	i = 0;
	if (min >= max)
		return (0);
	len = max - min;
	ran = (int *)malloc(sizeof(int) * len);
	if (!ran)
		return (0);
	while (i < len)
	{
		ran[i] = min;
		min++;
		i++;
	}
	return (ran);
}

// #include <stdio.h>
// int main(void)
// {
// 	int *ran;
// 	int i = 0;
// 	int min = 1;
// 	int max = 10;
// 	ran = ft_range(min, max);
// 	while (i < max - min)
// 	{
// 		printf("%d\n", ran[i]);
// 		i++;
// 	}
// }
