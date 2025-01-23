/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:13:25 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/29 23:31:08 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_read_dict(char *filename, int dict_len)
{
	int		fd;
	char	buf[1];
	char	*dict;
	int		i;

	i = 0;
	dict = (char *)malloc(sizeof(char) * dict_len + 1);
	if (!dict)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd)
	{
		while (read(fd, buf, 1))
			dict[i++] = buf[0];
		dict[i] = '\0';
	}
	close(fd);
	return (dict);
}

void	ft_count_dict_len(char *filename, int *len)
{
	int		fd;
	char	buf[1];

	len[0] = 0;
	fd = open(filename, O_RDONLY);
	if (fd)
	{
		while (read(fd, buf, 1))
		{
			len[0]++;
			if (buf[0] == '\n')
				len[1]++;
		}
	}
	close(fd);
}

char	**ft_sep_split(char **split, int len)
{
	char	**split2;
	int		i;
	int		j;
	int		s2_i;

	i = -1;
	s2_i = 0;
	split2 = (char **)malloc(sizeof(char *) * (len + 1));
	while (split[++i])
	{
		j = -1;
		while (split[i][++j])
		{
			if (split[i][j] == ':')
			{
				split2[s2_i++] = ft_strdup(&split[i][j + 1], -1);
				split[i][j] = '\0';
				break ;
			}
		}
	}
	split2[s2_i] = 0;
	return (split2);
}

void	ft_trim(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (split[i][j] == ' ')
			{
				split[i][j] = '\0';
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_make_dict(int ac, char **av, char ***key, char ***val)
{
	char	*dict;
	int		len[2];
	char	*filename;

	if (ac == 2)
		filename = "numbers.dict";
	else
		filename = av[ac - 2];
	ft_count_dict_len(filename, len);
	dict = ft_read_dict(filename, len[0]);
	*key = ft_split(dict, "\n");
	*val = ft_sep_split(*key, len[1]);
	ft_trim(*key);
	free(dict);
}
