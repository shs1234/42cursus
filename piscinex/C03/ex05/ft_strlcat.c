/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:59:32 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/22 21:44:17 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(dest);
	if (size < len)
		return (size + ft_strlen(src));
	while (len + i + 1 < size && src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (len + ft_strlen(src));
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char str3[40] = "BlockDMask";
//     char str4[7] = "Hell";

// 	printf("----------case1-------------\n");
// 	printf("intput\n");
//     printf("ft_strlcat count: %u\n", ft_strlcat(str3, str4, 10));
// 	printf("dest :%s\n", str3);

// 	printf("------------------------\n");
// 	char dest[40] = "BlockDMask";
//     char src[7] = "Hell";

// 	printf("ouput\n");
//     printf("strlcat count: %lu\n", strlcat(dest, src, 10));
// 	printf("dest :%s\n", dest);

// 	printf("\n");
// 	printf("----------case2-------------\n");
// 	char qw1[40] = "Bloae";
//     char ee1[7] = "Hell";

// 	printf("iutput\n");
//     printf("ft_strlcat count: %u\n", ft_strlcat(qw1, ee1,2 ));
// 	printf("dest :%s\n", qw1);

// 	printf("------------------------\n");

// 	char qw[40] = "Bloae";
//     char ee[7] = "Hell";

// 	printf("output\n");
//     printf("strlcat count: %lu\n", strlcat(qw, ee, 2));
// 	printf("dest :%s", qw);
// }