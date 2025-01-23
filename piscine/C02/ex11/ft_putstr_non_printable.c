/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:55:57 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/18 16:47:19 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_str_is_printable(char c)
{
	if (!(c >= 32 && c <= 126))
		return (0);
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i])
	{
		if (ft_str_is_printable(str[i]))
			ft_putchar(str[i]);
		else
		{
			c = (unsigned char)str[i];
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[c / 16]);
			ft_putchar("0123456789abcdef"[c % 16]);
		}
		i++;
	}
}

// #include <stdio.h>
// int main()
// {
// 	printf("< ex11 >\n");
// 	printf("-----------answer------------\n");
// 	printf("Coucou\\0atu vas bien ?\n");
// 	printf("\\c8\\7f\n");
// 	printf("-------------------------------\n");
// 	ft_putstr_non_printable("Concou\ntu vas bien ?");
// 	write(1, "\n", 1);
// 	char aa[3] = { 200, 127, 0};
// 	ft_putstr_non_printable(aa);
// 	printf("\n");
// 	printf("-----------output------------\n\n");
// }