/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:05:55 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/31 18:24:30 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
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
				if (ft_strcmp(tab[i], tab[i + 1]) > 0)
				{
					ft_swap(&tab[i], &tab[i + 1]);
					flag = 1;
				}
				i++;
			}
		}
	}
}
