/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:49:35 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/18 23:03:09 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	dest_i;
	int	src_i;

	dest_i = 0;
	src_i = 0;
	while (dest[dest_i])
		dest_i++;
	while (src[src_i])
	{
		dest[dest_i] = src[src_i];
		dest_i++;
		src_i++;
	}
	dest[dest_i] = '\0';
	return (dest);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	char s33[30] = "awd";
// 	char s34[10] = "awd";
// 	char s35[30] = "awd";
// 	char s36[10] = "awd";

// 	printf("----------case1-------------\n");
// 	printf("input\n");
// 	printf("ft_strcat : %s\n", ft_strcat(s33, s34));
// 	printf("answer\n");
// 	printf("strcat : %s\n", strcat(s35, s36));

// 	char a1[30] = "aa";
// 	char a2[10] = "c";
// 	char a3[30] = "aa";
// 	char a4[10] = "c";

// 	printf("----------case2-------------\n");
// 	printf("input\n");
// 	printf("ft_strcat : %s\n", ft_strcat(a1, a2));
// 	printf("answer\n");
// 	printf("strcat : %s\n", strcat(a3, a4));

// 	char a5[30] = "Hello";
// 	char a6[30] = "Helloaa";
// 	char a7[30] = "Hello";
// 	char a8[30] = "Helloaa";

// 	printf("----------case3-------------\n");
// 	printf("input\n");
// 	printf("ft_strcat: %s\n", ft_strcat(a5, a6));
// 	printf("answer\n");
// 	printf("strcat: %s\n", strcat(a7, a8));

// 	char a9[40] = "Hello";
// 	char a10[40] = "jaeyoondog";
// 	char a11[40] = "Hello";
// 	char a12[40] = "jaeyoondog";
// 	printf("----------case4-------------\n");
// 	printf("input\n");
// 	printf("ft_strcat: %s\n", ft_strcat(a9, a10));
// 	printf("answer\n");
// 	printf("strcat: %s\n", strcat(a11, a12));
// }