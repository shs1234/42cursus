/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:34:40 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/18 15:20:56 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>
// int main()
// {
// 	printf("< ex05 >\n");
// 	printf("-----------answer------------\n");
// 	printf("1 1 0\n");
// 	printf("-------------------------------\n");
// 	printf("%d %d %d\n", ft_str_is_uppercase("ASDFADFREGTHQFOZ"), 
// 	ft_str_is_uppercase(""), ft_str_is_uppercase("ASFR13Das"));
// 	printf("-----------output------------\n\n");
// }