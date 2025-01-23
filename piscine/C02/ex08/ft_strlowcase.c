/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:50:52 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/17 15:55:42 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

// #include <stdio.h>
// int main()
// {
// 	printf("< ex08 >\n");
// 	printf("-----------answer------------\n");
// 	printf("this is made by <haejokim>\n");
// 	printf("-------------------------------\n");
// 	char	made1[100] = "This is Made by <haejokim>";
// 	printf("%s\n", ft_strlowcase(made1));
// 	printf("-----------output------------\n\n");
// }