/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 00:51:52 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/23 00:20:15 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long long	ft_strlen(char *str)
{
	long long	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_base_chk(char *base)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i2 = i + 1;
		while (base[i2])
		{
			if (base[i] == base[i2])
				return (0);
			i2++;
		}
		i++;
	}
	return (1);
}

void	ft_print_base(long long nbr, char *base)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= ft_strlen(base))
		ft_print_base(nbr / ft_strlen(base), base);
	write(1, &base[nbr % ft_strlen(base)], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_base_chk(base))
		ft_print_base((long long)nbr, base);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("\n----ex04----\n");
// 	printf("  --base에 문제가 있는 경우 : 출력되는 것이 없어야 함--\n");
// 	ft_putnbr_base(123, "");
// 	printf("\nnbr : 123, base : null\n");
// 	ft_putnbr_base(123, "1");
// 	printf("\nnbr : 123, base : 1\n");
// 	ft_putnbr_base(123, "1123");
// 	printf("\nnbr : 123, base : 1123\n");
// 	ft_putnbr_base(123, "+123");
// 	printf("\nnbr : 123, base : +123\n");
// 	printf("  --base에 문제가 없는 경우 : 출력되는 것이 있어야 함--\n");
// 	ft_putnbr_base(2147483647, "poneyvif");
// 	printf("\nnbr : 2147483647, base : poneyvif\n");
// 	ft_putnbr_base(-2147483648, "0123456789abcdef");
// 	printf("\nnbr : -2147483648, base : 0123456789abcdef\n");
// 	ft_putnbr_base(-342373, "jungyeki");
// 	printf("\nnbr : -342373, base : jungyeki\n");
// }
