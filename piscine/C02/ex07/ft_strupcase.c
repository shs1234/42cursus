/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:39:12 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/17 15:55:47 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

// #include <stdio.h>
// int main()
// {
// 	char	made[100] = "This is Made by <haejokim>";
// 	printf("< ex07 >\n");
// 	printf("-----------answer------------\n");
// 	printf("THIS IS MADE BY <HAEJOKIM>\n");
// 	printf("-------------------------------\n");
// 	printf("%s\n", ft_strupcase(made));
// 	printf("-----------output------------\n\n");
// }