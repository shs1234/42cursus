/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:16:52 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/18 16:45:10 by hoseoson         ###   ########.fr       */
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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i + 1 < size && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char src[6] = "Hello";
// 	char	d5[10] = "abcabcabc";
// 	char	d6[10] = "abcabcabc";
// 	char	d7[10] = "abcabcabc";
// 	char	d8[10] = "abcabcabc";
// 	unsigned	int lcpy_return;
// 	printf("< ex10 >\n");
// 	printf("-----------answer------------\n");
// 	lcpy_return = strlcpy(d5, src, 3);
// 	printf("%d\n", lcpy_return);
// 	printf("%s\n", d5);
// 	printf("%s\n", &d5[6]);
// 	lcpy_return = strlcpy(d6, src, 8);
// 	printf("%d\n", lcpy_return);
// 	printf("%s\n", d6);
// 	printf("%s\n", &d6[6]);
// 	printf("-------------------------------\n");
// 	lcpy_return = ft_strlcpy(d7, src, 3);
// 	printf("%d\n", lcpy_return);
// 	printf("%s\n", d7);
// 	printf("%s\n", &d7[6]);
// 	lcpy_return = ft_strlcpy(d8, src, 8);
// 	printf("%d\n", lcpy_return);
// 	printf("%s\n", d8);
// 	printf("%s\n", &d8[6]);
// 	printf("-----------output------------\n\n");
// }