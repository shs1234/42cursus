/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 04:35:50 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/12 20:53:43 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pc;
	char	*copy;

	pc = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	copy = pc;
	if (!pc)
		return (NULL);
	while (*s1)
		*pc++ = *s1++;
	while (*s2)
		*pc++ = *s2++;
	*pc = 0;
	return (copy);
}
