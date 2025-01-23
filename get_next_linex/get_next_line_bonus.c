/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:08:58 by hoseoson          #+#    #+#             */
/*   Updated: 2023/08/26 02:03:10 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(char **mem)
{
	free(*mem);
	*mem = 0;
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*get_next_line(int fd)
{
	static char	*save[FD_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			len;
	char		*ret;

	ret = 0;
	len = 1;
	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (save[fd] && ft_ln_in_save(&save[fd], &ret))
		return (ret);
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
			return (ft_free(&save[fd]), ft_free(&ret), NULL);
		buf[len] = '\0';
		if (len && ft_ln_in_buf(buf, &save[fd], &ret))
			break ;
	}
	return (ret);
}
