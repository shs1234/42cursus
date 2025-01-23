/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:34:36 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/29 14:33:29 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_base_from_chk(char *base);
int	ft_strlen(char *str);

int	ft_base_to_chk(char *base)
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

char	*ft_make_res(long long nbr, char *base_to, int base_len, int res_len)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * res_len + 1);
	if (!res)
		return (0);
	if (nbr < 0)
	{
		res[0] = '-';
		nbr *= -1;
	}
	res[res_len] = '\0';
	if (nbr == 0)
		res[0] = base_to[0];
	while (nbr)
	{
		res[--res_len] = base_to[nbr % base_len];
		nbr /= base_len;
	}
	return (res);
}

int	ft_res_len(long long nbr, int base_len)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		i++;
	while (nbr)
	{
		nbr /= base_len;
		i++;
	}
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	nbr_l;
	int			base_len;
	char		*res;

	if (!ft_base_from_chk(base_from) || !ft_base_to_chk(base_to))
		return (0);
	nbr_l = ft_atoi_base(nbr, base_from);
	base_len = ft_strlen(base_to);
	res = ft_make_res(nbr_l, base_to, base_len, ft_res_len(nbr_l, base_len));
	return (res);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%s", ft_convert_base("-0", "0123456789", "0123456"));
// }
