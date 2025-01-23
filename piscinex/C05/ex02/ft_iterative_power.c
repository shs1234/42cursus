/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:40:09 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/23 00:52:27 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	res;

	res = 1;
	i = 0;
	if (nb == 0 && power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (i < power)
	{
		res *= nb;
		i++;
	}
	return (res);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d", ft_iterative_power(-2, 5));
// 	return (0);
// }
