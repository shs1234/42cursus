/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:23:22 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/18 15:20:08 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>
// int main()
// {
// 	printf("-----------answer------------\n");
// 	printf("1 1 0\n");
// 	printf("-------------------------------\n");
// 	printf("%d %d %d\n", ft_str_is_numeric(""), 
// 	ft_str_is_numeric("123413499"), ft_str_is_numeric("124\n"));
// 	printf("-----------output------------\n\n");
// }