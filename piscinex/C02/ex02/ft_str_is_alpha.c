/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:08:47 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/18 15:19:58 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')))
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>
// int main()
// {
// 	printf("< ex02 >\n");
// 	printf("-----------answer------------\n");
// 	printf("1 1 0\n");
// 	printf("-------------------------------\n");
// 	printf("%d %d %d\n", ft_str_is_alpha("afwrA"), 
// 	ft_str_is_alpha(""), ft_str_is_alpha("asA \n"));
// 	printf("-----------output------------\n\n");
// }