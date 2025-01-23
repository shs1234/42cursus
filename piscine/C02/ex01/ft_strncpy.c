/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:25:42 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/19 16:28:48 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char src[6] = "Hello";
// 	char d1[10] = "abcabcabc";
// 	char d2[10] = "abcabcabc";
// 	char d3[10] = "abcabcabc";
// 	char d4[10] = "abcabcabc";
// 	strncpy(d1, src, 3); //src보다 작은 사이즈가 주어질 때 널이 없음!
// 	printf("%s\n", d1);
// 	printf("%s\n", &d1[6]);
// 	strncpy(d2, src, 8);
// 	printf("%s\n", d2);
// 	printf("%s\n", &d2[7]); //null이 다 채워졌는지 체크
// 	printf("바로 위의 값은 무시. 문제 정의 상에서는 null로 채워져 프린트되지 않아야함\n");
// 	printf("-------------------------------\n");
// 	ft_strncpy(d3, src, 3);
// 	printf("%s\n", d3);
// 	printf("%s\n", &d3[6]);
// 	ft_strncpy(d4, src, 8);
// 	printf("%s\n", d4);
// 	printf("%s\n", &d4[7]);
// 	printf("-----------output------------\n\n");
// }
