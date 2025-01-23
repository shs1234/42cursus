/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:31:19 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/29 23:26:53 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_print_100(int num, char *out, char **key, char **val)
{
	if (num / 100)
	{
		out[1] = '\0';
		out[0] = num / 100 + '0';
		ft_print(out, key, val);
		write(1, " ", 1);
		out[1] = '0';
		ft_print("100", key, val);
		if (num % 100 > 0)
			write(1, " and ", 5);
	}
	out[2] = '\0';
}

void	ft_print_2099(int num, char *out, char **key, char **val)
{
	out[0] = num / 10 + '0';
	out[1] = '0';
	ft_print(out, key, val);
	if (num % 10 != 0)
	{
		write(1, "-", 1);
		out[0] = num % 10 + '0';
		out[1] = '\0';
		ft_print(out, key, val);
	}
}

void	ft_print_1019(int num, char *out, char **key, char **val)
{
	out[0] = num / 10 + '0';
	out[1] = num % 10 + '0';
	ft_print(out, key, val);
}

void	ft_print_0109(int num, char *out, char **key, char **val)
{
	out[0] = num % 10 + '0';
	out[1] = '\0';
	ft_print(out, key, val);
}

void	ft_print(char *num, char **key, char **val)
{
	int		i;
	int		j;
	char	**val_split;

	i = 0;
	j = 0;
	while (key[i] != 0)
	{
		if (ft_strcmp(num, key[i]) == 0)
		{
			val_split = ft_split(val[i], " ");
			while (val_split[j])
			{
				ft_putstr(val_split[j]);
				if (val_split[j + 1] != 0)
					write(1, " ", 1);
				j++;
			}
		}
		i++;
	}
	i = 0;
	while (val_split[i])
		free(val_split[i++]);
	free(val_split);
}
