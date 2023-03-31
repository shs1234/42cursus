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

	buf = 0;
	ret = 0;
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
				save = ft_strdup(save, &save[i + 1]);
				if (!save)
					return (ft_free(&buf), ft_free(&ret), NULL);
			}
			else
				ft_free(&save);
			return (ft_free(&buf), ret);
		}
	}
	while (1)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
			return (ft_free(&save), ft_free(&buf), ft_free(&ret), NULL);
		else if (len == 0)
		{
			if (ret)
				return (ft_free(&buf), ft_free(&save), ret);
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
						save = ft_strdup(save, &save[i + 1]);
						if (!save)
							return (ft_free(&buf), ft_free(&ret), NULL);
					}
					else
						ft_free(&save);
				}
				else
				{
					ret = save;
					save = 0;
				}
			}
			break ;
		}
		else
		{
			buf[len] = '\0';
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
						save = ft_strdup(save, &save[i + 1]);
						if (!save)
							return (ft_free(&buf), ft_free(&ret), NULL);
					}
					else
						ft_free(&save);
				}
				else
				{
					ret = save;
					save = 0;
				}
			}
			i = ft_has_newline(buf);
			if (i >= 0)
			{
				ret = ft_strjoin(ret, buf, i);
				if (!ret)
					return (ft_free(&buf), ft_free(&save), NULL);
				if (buf[i + 1])
				{
					save = ft_strdup(save, &buf[i + 1]);
					if (!save)
						return (ft_free(&buf), ft_free(&ret), NULL);
				}
				break ;
			}
			else
			{
				ret = ft_strjoin(ret, buf, i);
				if (!ret)
					return (ft_free(&buf), ft_free(&save), NULL);
			}
		}
	}
	return (ft_free(&buf), ret);
}
