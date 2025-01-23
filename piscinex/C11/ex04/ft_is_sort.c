/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:09:13 by hoseoson          #+#    #+#             */
/*   Updated: 2023/02/01 16:14:11 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asc;
	int	des;
	int	same;

	i = 0;
	asc = 0;
	des = 0;
	same = 0;
	if (length == 0)
		return (1);
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			asc++;
		if (f(tab[i], tab[i + 1]) <= 0)
			des++;
		if (f(tab[i], tab[i + 1]) == 0)
			same++;
		i++;
	}
	if (asc == length - 1 || des == length - 1 || same == length - 1)
		return (1);
	return (0);
}
