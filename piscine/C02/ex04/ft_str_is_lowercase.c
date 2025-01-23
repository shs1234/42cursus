/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:33:18 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/18 15:20:20 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>
// int main()
// {
// 	printf("< ex04 >\n");
// 	printf("-----------answer------------\n");
// 	printf("1 1 0\n");
// 	printf("-------------------------------\n");
// 	printf("%d %d %d\n", ft_str_is_lowercase("asdfj"), 
// 	ft_str_is_lowercase(""), ft_str_is_lowercase("asdfAA13"));
// 	printf("-----------output------------\n\n");
// }