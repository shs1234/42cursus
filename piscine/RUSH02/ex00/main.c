/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:55:36 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/29 23:33:17 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_main_error(int ac, char **av)
{
	int	flag;

	flag = 0;
	if (!(ac == 2 || ac == 3))
	{
		write(1, "Error\n", 6);
		flag = 1;
	}
	if (ac == 3)
	{
		if (open(av[1], O_RDONLY) < 0)
		{
			write(1, "Dict Error\n", 11);
			flag = 1;
		}
	}
	return (flag);
}

int	ft_main_error2(int *len)
{
	if ((len[1] == 0 && len[2] == 0) || len[3] == 1)
	{	
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

void	ft_free(char *str, char **key, char **val)
{
	int	i;

	i = 0;
	free(str);
	while (key[i])
	{
		free(key[i]);
		i++;
	}
	i = 0;
	while (val[i])
	{
		free(val[i]);
		i++;
	}
	free(key);
	free(val);
}

int	ft_main_error3(int *len, char **key, char **val)
{
	int	flag;

	flag = 0;
	if (len[2] == 1)
	{
		ft_zero_print(key, val);
		flag = 1;
	}
	if (!ft_val_valid(val) || len[1] >= 40)
	{
		write(1, "Dict Error\n", 11);
		flag = 1;
	}
	return (flag);
}

int	main(int ac, char **av)
{
	char	*str;
	int		len[4];
	int		i;
	char	**key;
	char	**val;

	i = 0;
	if (ft_main_error(ac, av))
		return (0);
	len[1] = ft_atoi_len(av[ac - 1], len);
	if (ft_main_error2(len))
		return (0);
	str = ft_strdup(&av[ac - 1][len[0]], len[1]);
	ft_make_dict(ac, av, &key, &val);
	if (ft_main_error3(len, key, val))
	{
		ft_free(str, key, val);
		return (0);
	}
	convert_to_str(str, key, val);
	ft_free(str, key, val);
	return (0);
}
