/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:45:28 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/29 23:38:50 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] >= 33 && str[i] <= 126)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_val_valid(char **key)
{
	int	i;

	i = 0;
	while (key[i])
	{
		if (!ft_is_printable(key[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_zero_print(char **key, char **val)
{
	int		i;
	int		j;
	char	**val_split;

	i = -1;
	j = 0;
	while (key[++i] != 0)
	{
		if (ft_strcmp("0", key[i]) == 0)
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
	}
	write(1, "\n", 1);
	i = 0;
	while (val_split[i])
		free(val_split[i++]);
	free(val_split);
}
