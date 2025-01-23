/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:16:19 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/21 23:21:34 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_valid_line(int *line, int con1, int con2);
int	ft_view_condition(char *str, int *tab, int index, int n);
int	ft_condition(char *str, int *tab, int index, int n);
int	ft_input_check(char **av);

int	ft_valid_line_rev(int *line, int con)
{
	int	max;
	int	i;
	int	count;

	max = line[3];
	i = 2;
	count = 1;
	while (i >= 0)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i--;
	}
	if (count == con)
		return (1);
	else
		return (0);
}

int	ft_valid_line(int *line, int con1, int con2)
{
	int	max;
	int	i;
	int	count;

	max = line[0];
	i = 1;
	count = 1;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	if (count == con1 && ft_valid_line_rev(line, con2))
		return (1);
	else
		return (0);
}

int	ft_view_condition(char *str, int *tab, int index, int n)
{
	int	line[4];

	if (index % 4 == 3)
	{
		line[0] = tab[((index / 4) * 4) + 0];
		line[1] = tab[((index / 4) * 4) + 1];
		line[2] = tab[((index / 4) * 4) + 2];
		line[3] = n;
		if (!ft_valid_line(line, str[16 + ((index / 4) * 2)] - '0',
				str[24 + ((index / 4) * 2)] - '0'))
			return (0);
	}
	if (index >= 12 && index <= 15)
	{
		line[0] = tab[index - (4 * 3)];
		line[1] = tab[index - (4 * 2)];
		line[2] = tab[index - (4 * 1)];
		line[3] = n;
		if (!ft_valid_line(line, str[(index - 12) * 2] - '0',
				str[8 + ((index - 12) * 2)] - '0'))
			return (0);
	}
	return (1);
}

int	ft_condition(char *str, int *tab, int index, int n)
{
	int	row;
	int	col;

	row = index / 4;
	col = index % 4;
	while (row)
	{
		if (n == tab[index - (4 * row)])
			return (0);
		row--;
	}
	while (col)
	{
		if (n == tab[index - (1 * col)])
			return (0);
		col--;
	}
	if ((index >= 12 && index <= 15) || index % 4 == 3)
	{
		if (!ft_view_condition(str, tab, index, n))
			return (0);
	}
	return (1);
}

int	ft_input_check(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
		i++;
	if (i != 31)
		return (0);
	i = 0;
	while (i < 31)
	{
		if (i % 2 == 0)
		{
			if (!(av[1][i] >= '1' && av[1][i] <= '4'))
				return (0);
		}
		else
		{
			if (!(av[1][i] == ' '))
				return (0);
		}
		i++;
	}
	return (1);
}
