/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:29:09 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/25 09:58:13 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (!dup)
		return (0);
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *str = "hello world!";
// 	printf("%s", ft_strdup(str));
// }