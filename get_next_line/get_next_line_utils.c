/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:36:08 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/28 13:18:15 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_has_newline(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
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

char	*ft_strjoin(char *s1, char *s2, int i)
{
	char	*ret;
	char	*ret_start;
	char	*tmp;
	int		s1_len;

	if (!s1)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	if (i == -1)
		i = ft_strlen(s2) - 1;
	ret = (char *)malloc(sizeof(char) * (s1_len + i + 2));
	if (!ret)
		return (ft_free(&s1), NULL);
	ret_start = ret;
	tmp = s1;
	while (s1_len--)
		*ret++ = *s1++;
	i++;
	while (i--)
		*ret++ = *s2++;
	*ret = '\0';
	return (ft_free(&tmp), ret_start);
}

char	*ft_strdup(char *save, char *s1)
{
	char	*dup;
	char	*dup_start;
	int		len;

	if (!s1)
		len = 0;
	else
		len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (!dup)
		return (ft_free(&save), NULL);
	dup_start = dup;
	while (len--)
		*dup++ = *s1++;
	*dup = '\0';
	return (ft_free(&save), dup_start);
}
