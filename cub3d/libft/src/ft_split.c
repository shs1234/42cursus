/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:11:12 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/12 20:53:24 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_s(char const *s, char c)
{
	int	str_n;

	str_n = 0;
	while (*s)
	{
		if (*s != c)
		{
			str_n++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (str_n);
}

int	count_c(char const *s, char c)
{
	int	cnt;

	cnt = -1;
	while (s[++cnt] && s[cnt] != c)
		;
	return (cnt);
}

void	fill_pc_split(char **ppc, char const *s, int ppc_i, int pc_size)
{
	int	pc_i;

	pc_i = -1;
	while (++pc_i < pc_size)
		ppc[ppc_i][pc_i] = s[pc_i];
}

int	fill_ppc(char **ppc, char const *s, char c)
{
	int		ppc_i;
	int		pc_size;

	ppc_i = -1;
	while (*s)
	{
		pc_size = count_c(s, c);
		if (pc_size)
		{
			ppc[++ppc_i] = (char *)malloc(sizeof(char) * (pc_size + 1));
			if (!ppc[ppc_i])
				return (0);
			ppc[ppc_i][pc_size] = 0;
			fill_pc_split(ppc, s, ppc_i, pc_size);
			s += pc_size;
		}
		else
			s++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ppc;
	int		str_n;
	int		i;

	if (!s)
		return (NULL);
	str_n = count_s(s, c);
	ppc = (char **)malloc(sizeof(char *) * (str_n + 1));
	if (!ppc)
		return (NULL);
	ppc[str_n] = NULL;
	if (!fill_ppc(ppc, s, c))
	{
		i = -1;
		while (ppc[++i] && i < str_n)
			free(ppc[i]);
		free(ppc);
		return (NULL);
	}
	return (ppc);
}
