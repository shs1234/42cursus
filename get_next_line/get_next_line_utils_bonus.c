/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:08:53 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/02 21:46:38 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

int	ft_ln_in_save(char **save, char **ret, char **savelist)
{
	int	i;

	i = ft_has_newline(*save);
	if (i >= 0)
	{
		*ret = ft_strjoin(*ret, *save, i);
		if (!(*ret))
		{
			ft_free_savelist(savelist);
			return (1);
		}
		if ((*save)[i + 1])
		{
			*save = ft_strdup(&(*save)[i + 1], *save);
			if (!(*save))
				ft_free(ret);
		}
		else
			ft_free_savelist(savelist);
		return (1);
	}
	*ret = *save;
	*save = 0;
	return (0);
}

int	ft_ln_in_buf(char *buf, char **save, char **ret, char **savelist)
{
	int	i;

	i = ft_has_newline(buf);
	if (i >= 0)
	{
		*ret = ft_strjoin(*ret, buf, i);
		if (!(*ret))
		{
			ft_free_savelist(savelist);
			return (1);
		}
		if (buf[i + 1])
		{
			*save = ft_strdup(&buf[i + 1], *save);
			if (!(*save))
				ft_free(ret);
		}
		return (1);
	}
	*ret = ft_strjoin(*ret, buf, i);
	return (0);
}

char	*ft_strjoin(char *s1, const char *s2, int i)
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

char	*ft_strdup(const char *s1, char *save)
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
