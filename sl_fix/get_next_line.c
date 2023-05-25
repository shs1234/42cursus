/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:36:08 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/16 14:43:58 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_ln_in_save(char **save, char **ret);
static int	ft_ln_in_buf(char *buf, char **save, char **ret);
static char	*ft_strjoin_gnl(char *s1, const char *s2, int i);
static char	*ft_strdup_gnl(const char *s1, char *save);

static int	ft_ln_in_save(char **save, char **ret)
{
	int	i;

	i = ft_has_newline(*save);
	if (i >= 0)
	{
		*ret = ft_strjoin_gnl(*ret, *save, i);
		if (!(*ret))
		{
			ft_free(save);
			return (1);
		}
		if ((*save)[i + 1])
		{
			*save = ft_strdup_gnl(&(*save)[i + 1], *save);
			if (!(*save))
				ft_free(ret);
		}
		else
			ft_free(save);
		return (1);
	}
	*ret = *save;
	*save = 0;
	return (0);
}

static int	ft_ln_in_buf(char *buf, char **save, char **ret)
{
	int	i;

	i = ft_has_newline(buf);
	if (i >= 0)
	{
		*ret = ft_strjoin_gnl(*ret, buf, i);
		if (!(*ret))
		{
			ft_free(save);
			return (1);
		}
		if (buf[i + 1])
		{
			*save = ft_strdup_gnl(&buf[i + 1], *save);
			if (!(*save))
				ft_free(ret);
		}
		return (1);
	}
	*ret = ft_strjoin_gnl(*ret, buf, i);
	return (0);
}

static char	*ft_strjoin_gnl(char *s1, const char *s2, int i)
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

static char	*ft_strdup_gnl(const char *s1, char *save)
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
