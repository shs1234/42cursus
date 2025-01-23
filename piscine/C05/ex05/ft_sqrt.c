/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:16:17 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/24 14:44:33 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
//         printf("sqrt of %d is %d\n", -603, ft_sqrt(-603));
//         printf("sqrt of %d is %d\n", 0, ft_sqrt(0));
//         printf("sqrt of %d is %d\n", 1, ft_sqrt(1));
//         printf("sqrt of %d is %d\n", 2, ft_sqrt(2));
//         printf("sqrt of %d is %d\n", 1640045925, ft_sqrt(1640045925));
//         printf("sqrt of %d is %d\n", 2147395600, ft_sqrt(2147395600));
//         printf("sqrt of %d is %d\n", 2147483646, ft_sqrt(2147483646));
//         printf("sqrt of %d is %d\n", 342694144, ft_sqrt(342694144));
//         printf("sqrt of %d is %d\n", 1271317200, ft_sqrt(1271317200));
//         printf("sqrt of %d is %d\n", 140778225, ft_sqrt(140778225));
//         printf("sqrt of %d is %d\n", 856750425, ft_sqrt(856750425));
//         printf("sqrt of %d is %d\n", 1393603561, ft_sqrt(1393603561));
//         printf("sqrt of %d is %d\n", 900804844, ft_sqrt(900804844));
//         printf("sqrt of %d is %d\n", 309091561, ft_sqrt(309091561));
//         printf("sqrt of %d is %d\n", 377970629, ft_sqrt(377970629));
//         printf("sqrt of %d is %d\n", 80982001, ft_sqrt(80982001));
//         printf("sqrt of %d is %d\n", 839827630, ft_sqrt(839827630));
// }

// sqrt of -603 is 0
// sqrt of 0 is 0
// sqrt of 1 is 1
// sqrt of 2 is 0
// sqrt of 1640045925 is 0
// sqrt of 2147395600 is 46340
// sqrt of 2147483646 is 0
// sqrt of 342694144 is 18512
// sqrt of 1271317200 is 0
// sqrt of 140778225 is 11865
// sqrt of 856750425 is 0
// sqrt of 1393603561 is 37331
// sqrt of 900804844 is 0
// sqrt of 309091561 is 17581
// sqrt of 377970629 is 0
// sqrt of 80982001 is 8999
// sqrt of 839827630 is 0