/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:24:42 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/31 18:29:58 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	if (tab[i] && tab[i + 1])
	{
		while (flag)
		{
			flag = 0;
			i = 0;
			while (tab[i + 1])
			{
				if (cmp(tab[i], tab[i + 1]) > 0)
				{
					ft_swap(&tab[i], &tab[i + 1]);
					flag = 1;
				}
				i++;
			}
		}
	}
}
