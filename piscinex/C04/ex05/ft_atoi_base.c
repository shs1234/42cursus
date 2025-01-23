/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:26:57 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/23 00:19:16 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

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
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
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

int	ft_i_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	res;

	sign = 1;
	i = 0;
	res = 0;
	if (!ft_base_chk(base))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_i_in_base(str[i], base) != -1)
	{
		res = ft_strlen(base) * res + ft_i_in_base(str[i], base);
		i++;
	}
	return (res * sign);
}

// #include <stdio.h>
// int main()
// {
// 	printf("  --base에 문제가 있는 경우 : 0이 출력되야 함--\n");
// 	printf("%d", ft_atoi_base("123", ""));
// 	printf("\nnbr : 123, base : null\n");
// 	printf("%d", ft_atoi_base("123", "1"));
// 	printf("\nnbr : 123, base : 1\n");
// 	printf("%d", ft_atoi_base("123", "1123"));
// 	printf("\nnbr : 123, base : 1123\n");
// 	printf("%d", ft_atoi_base("123", "+123"));
// 	printf("\nnbr : 123, base : +123\n");
// 	printf("  --base에 문제가 없는 경우 : 출력되는 것이 있어야 함--\n");
// 	printf("%d", ft_atoi_base("offffffffff", "poneyvif"));
// 	printf("\nstr : offffffffff, base : poneyvif\n");
// 	printf("%d", ft_atoi_base("-80000000","0123456789abcdef"));
// 	printf("\nstr : -80000000, base : 0123456789abcdef\n");
// 	printf("%d", ft_atoi_base("    ----++---+jungyeye0224", "jungyeki"));
// 	printf("\nstr :     ----++---+jungyeye0224, base : jungyeki\n");
// }