/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:35:50 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/28 14:14:52 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **mem)
{
	free(*mem);
	*mem = 0;
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	int			len;
	char		*ret;
	int			i;

	ret = 0;
	len = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (ft_free(&save), NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free(&save), NULL);
	if (save)
	{
		i = ft_has_newline(save);
		if (i >= 0)
		{
			ret = ft_strjoin(ret, save, i);
			if (!ret)
				return (ft_free(&buf), ft_free(&save), NULL);
			if (save[i + 1])
			{
				save = ft_strdup(&save[i + 1], save);
				if (!save)
					return (ft_free(&buf), ft_free(&ret), NULL);
			}
			else
				ft_free(&save);
			return (ft_free(&buf), ret);
		}
	}
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		ft_has_save(&save, &ret);
		if (len == -1)
			return (ft_free(&save), ft_free(&buf), ft_free(&ret), NULL);
		buf[len] = '\0';
		if (buf[0])
		{
			i = ft_has_newline(buf);
			if (i >= 0)
			{
				ret = ft_strjoin(ret, buf, i);
				if (!ret)
					return (ft_free(&buf), ft_free(&save), NULL);
				if (buf[i + 1])
				{
					save = ft_strdup(&buf[i + 1], save);
					if (!save)
						return (ft_free(&buf), ft_free(&ret), NULL);
				}
				else
					ft_free(&buf);
				return (ft_free(&buf), ret);
			}
			ret = ft_strjoin(ret, buf, i);
		}
	}
	return (ft_free(&buf), ret);
}
