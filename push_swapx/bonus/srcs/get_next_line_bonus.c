/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:35:50 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/26 03:52:34 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free(char **mem)
{
	free(*mem);
	*mem = 0;
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		buf[BUFFER_SIZE + 1];
	int			len;
	char		*ret;

	ret = 0;
	len = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (save && ft_ln_in_save(&save, &ret))
		return (ret);
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
			return (ft_free(&save), ft_free(&ret), NULL);
		buf[len] = '\0';
		if (len && ft_ln_in_buf(buf, &save, &ret))
			break ;
	}
	return (ret);
}
