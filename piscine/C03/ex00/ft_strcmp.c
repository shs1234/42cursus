/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:17:23 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/22 00:15:11 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char s1[10] = "awd";
// 	char s2[10] = "awd";
// 	char s3[10] = "awd";
// 	char s4[10] = "awd";

// 	printf("----------case1-------------\n");
// 	printf("input\n");
// 	printf("ft_strcmp : %d\n", ft_strcmp(s1, s2));
// 	printf("answer\n");
// 	printf("strcmp : %d\n", strcmp(s3, s4));

// 	char s5[10] = "aa";
// 	char s6[10] = "c";
// 	char s7[10] = "aa";
// 	char s8[10] = "c";
// 	printf("----------case2-------------\n");
// 	printf("input\n");
// 	printf("ft_strcmp : %d\n", ft_strcmp(s5, s6));
// 	printf("answer\n");
// 	printf("strcmp : %d\n", strcmp(s7, s8));

// 	char s9[10] = "cc";
// 	char s10[10] = "a";
// 	char s11[10] = "cc";
// 	char s12[10] = "a";
// 	printf("----------case3-------------\n");
// 	printf("input\n");
// 	printf("ft_strcmp: %d\n", ft_strcmp(s9, s10));
// 	printf("answer\n");
// 	printf("strcmp: %d\n", strcmp(s11, s12));

// 	char	our_1[10] = {'H', 'E', 'L', 'L', 'O'};
// 	char	our_2[10] = {'H', 'E', 'L', 150, 'O'};
// 	char	our_3[10] = {'H', 'E', 'L', 'L', 'O'};
// 	char	our_4[10] = {'H', 'E', 'L', 150, 'O'};
// 	printf("----------case4-------------\n");
// 	printf("input\n");
// 	printf("ft_strcmp: %d\n", ft_strcmp(our_1, our_2));
// 	printf("answer\n");
// 	printf("strcmp: %d\n", strcmp(our_3, our_4));
// }