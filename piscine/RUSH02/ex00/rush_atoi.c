/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:16:35 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/29 22:21:53 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_atoi_len(char *str, int *len)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	len[2] = 0;
	len[3] = 0;
	while ((str[start] >= 9 && str[start] <= 13) || str[start] == 32)
		start++;
	if (str[start] == '+' || str[start] == '-')
	{
		if (str[start] == '+')
			start++;
		else
			return (0);
	}
	while (str[start] == '0')
	{
		len[2] = 1;
		start++;
	}
	len[0] = start;
	ft_atoi_len2(str, len, &start, &end);
	return (end);
}

void	ft_atoi_len2(char *str, int *len, int *start, int *end)
{
	while (str[*start] >= '0' && str[*start] <= '9')
	{
		(*start)++;
		(*end)++;
		len[2] = 0;
		if (str[*start])
		{
			if (str[*start] == '.'
				&& (str[(*start) + 1] >= '0' && str[(*start) + 1] <= '9'))
				len[3] = 1;
		}
	}
}
