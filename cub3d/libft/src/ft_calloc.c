/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:52:19 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/12 20:35:58 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pv;

	if (count == (size_t)-1 || size == (size_t)-1)
		return (NULL);
	pv = malloc(count * size);
	if (pv == NULL)
		return (NULL);
	return (ft_memset(pv, 0, count * size));
}
