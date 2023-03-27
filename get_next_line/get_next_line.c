/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:35:50 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/28 01:40:54 by hoseoson         ###   ########.fr       */
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
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*sub;
	int		i;

	if (!s)
		return (0);
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (0);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}

char	**ft_joinsplit(t_list *lst)
{
	char	*join;
	int		len;
	char	**split;
	int		i;

	join = (char *)malloc(sizeof(char) * ft_lstsize(lst) * BUFFER_SIZE + 1);
	if (!join)
		return (0);
	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			join[len + i] = lst->content[i];
			i++;
		}
		len += i;
		lst = lst->next;
	}
	join[len] = 0;
	split = ft_split(join, '\n');
	free(join);
	return (split);
}

char	*get_next_line(int fd)
{
	static char	**split;
	char		buf[BUFFER_SIZE + 1];
	t_list		*lst;
	static int	i;
	int			len;

	if (split == 0 || split[i] == 0 || split[i + 1] == 0)
	{
		lst = 0;
		if (split != 0 && split[i] && split[i + 1] == 0)
		{
			ft_lstadd_back(&lst, ft_lstnew(split[i]));
			i = 0;
			while (split[i])
				free(split[i++]);
			free(split);
		}
		i = 0;
		while (1)
		{
			len = read(fd, buf, BUFFER_SIZE);
			buf[len] = 0;
			ft_lstadd_back(&lst, ft_lstnew(buf));
			if (ft_has_newline(buf) || len == 0)
				break ;
		}
		split = ft_joinsplit(lst);
	}
	return (split[i++]);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("test", O_RDONLY);
	while (i < 11)
	{
		line = get_next_line(fd);
		printf(">>>>>%d : %s", i + 1, line);
		i++;
	}
	printf("\n");
	// system("leaks a.out");
}
