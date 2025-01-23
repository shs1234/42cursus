/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:36:15 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/18 15:21:39 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>
// int main()
// {
// 	char	s1[2] = { 127 };
// 	char	s2[2] = { 0 };
// 	char	s3[3] = { 31 };
// 	char	s4[4] = { 32, 55, 95 };
// 	char	s5[2] = {200};
// 	printf("< ex06 >\n");
// 	printf("-----------answer------------\n");
// 	printf("0 1 0 1 0\n");
// 	printf("-------------------------------\n");
// 	printf("%d %d %d %d %d\n", 
// 	ft_str_is_printable(s1), ft_str_is_printable(s2), ft_str_is_printable(s3), 
// 	ft_str_is_printable(s4), ft_str_is_printable(s5));
// 	printf("-----------output------------\n\n");
// }