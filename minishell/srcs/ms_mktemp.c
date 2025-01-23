/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_mktemp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 07:18:02 by hoseoson          #+#    #+#             */
/*   Updated: 2023/07/04 15:03:16 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	file_exists(const char *filename)
{
	struct stat	buf;

	return (stat(filename, &buf) == 0);
}

char	*ms_mktemp(char *template)
{
	char	*temp;
	int		i;
	char	*num;

	i = 0;
	while (i < TMAXCOUNT)
	{
		num = ft_itoa(i);
		if (!num)
			return (NULL);
		temp = ft_strjoin(template, num);
		if (!temp)
			return (NULL);
		free(num);
		if (!file_exists(temp))
			return (temp);
		free(temp);
		i++;
	}
	return (NULL);
}
