/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:31:09 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/15 21:53:04 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_row(char first, char mid, char last, int x)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0)
			ft_putchar(first);
		else if (col == x - 1)
			ft_putchar(last);
		else
			ft_putchar(mid);
		col++;
	}
}

void	rush(int x, int y)
{
	int	row;

	row = 0;
	while (row < y)
	{
		if (row == 0)
			print_row('o', '-', 'o', x);
		else if (row == y - 1)
			print_row('o', '-', 'o', x);
		else
			print_row('|', ' ', '|', x);
		ft_putchar('\n');
		row++;
	}
}
