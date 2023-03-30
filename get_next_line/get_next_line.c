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

// char	*ft_substr(char const *s, unsigned int start, int len)
// {
// 	char	*sub;
// 	int		i;

// 	if (!s)
// 		return (0);
// 	sub = (char *)malloc(sizeof(char) * len + 1);
// 	if (!sub)
// 		return (0);
// 	i = 0;
// 	while (i < len)
// 	{
// 		sub[i] = s[start + i];
// 		i++;
// 	}
// 	sub[i] = 0;
// 	return (sub);
// }

// char	**ft_joinsplit(t_list *lst)
// {
// 	char	*join;
// 	int		len;
// 	char	**split;
// 	int		i;

// 	join = (char *)malloc(sizeof(char) * ft_lstsize(lst) * BUFFER_SIZE + 1);
// 	if (!join)
// 		return (0);
// 	len = 0;
// 	while (lst)
// 	{
// 		i = 0;
// 		while (lst->content[i])
// 		{
// 			join[len + i] = lst->content[i];
// 			i++;
// 		}
// 		len += i;
// 		lst = lst->next;
// 	}
// 	join[len] = 0;
// 	split = ft_split(join, '\n');
// 	free(join);
// 	return (split);
// }

// char	*get_next_line(int fd)
// {
// 	static char	**split;
// 	char		buf[BUFFER_SIZE + 1];
// 	t_list		*lst;
// 	static int	i;
// 	static int	len;

// 	if (BUFFER_SIZE <= 0 || fd < 3)
// 		return (0);
// 	if (split == 0 || split[i] == 0 || split[i + 1] == 0)
// 	{
// 		lst = 0;
// 		if (split != 0)
// 		{
// 			if (split[0] && split[1] == 0 && len == 0)
// 				return (0);
// 			ft_lstadd_back(&lst, ft_lstnew(split[i]));
// 			i = 0;
// 			while (split[i])
// 				free(split[i++]);
// 			free(split);
// 		}
// 		i = 0;
// 		while (1)
// 		{
// 			len = read(fd, buf, BUFFER_SIZE);
// 			buf[len] = 0;
// 			printf(" len : %d ", len);
// 			ft_lstadd_back(&lst, ft_lstnew(buf));
// 			if (ft_has_newline(buf) || len == 0)
// 				break ;
// 		}
// 		split = ft_joinsplit(lst);
// 	}
// 	int k=0;
// 	while (split[k])
// 	{
// 		printf("split[%d] : %s\n",k, split[k]);
// 		k++;
// 	}
// 	return (split[i++]);
// }


// void ft_savesplit(char *save, char **ret)
// {
// 	int i;
	
// 	if (save)
// 	{
// 		i = ft_has_newline(save);
// 		if (i >= 0)
// 		{
// 			*ret = ft_strjoin(*ret, save, i);
// 			if (save[i + 1])
// 				save = ft_strdup(save, &save[i + 1]);
// 			else
// 			{
// 				free(save);
// 				save = 0;
// 			}
// 		}
// 	}
// }
// 

char	*get_next_line(int fd)
{
	static char	*save;
	char *buf;
	int			len;
	char		*ret;
	int			i;

	ret = 0;
	if (fd == 1 || fd == 2 || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (save)
	{
		i = ft_has_newline(save);
		if (i >= 0)
		{
			ret = ft_strjoin(ret, save, i);
			if (save[i + 1])
				save = ft_strdup(save, &save[i + 1]);
			else
			{
				free(save);
				save = 0;
			}
			free(buf);
			return (ret);
		}
	}
	while (1)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
		{
			free(buf);
			return (NULL);
		}
		else if (len == 0)
		{
			if (ret)
			{
				free(buf);
				return (ret);
			}
			if (save)
			{
				i = ft_has_newline(save);
				if (i >= 0)
				{
					ret = ft_strjoin(ret, save, i);
					if (save[i + 1])
						save = ft_strdup(save, &save[i + 1]);
					else
					{
						free(save);
						save = 0;
					}
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
					if (save[i + 1])
						save = ft_strdup(save, &save[i + 1]);
					else
					{
						free(save);
						save = 0;
					}
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
				if (buf[i + 1])
					save = ft_strdup(save, &buf[i + 1]);
				break;
			}
			else
				ret = ft_strjoin(ret, buf, i);
		}
	}
	free(buf);
	return (ret);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	fd = open("test", O_RDONLY);
// 	while (i < 9)
// 	{
// 		line = get_next_line(fd);
// 		printf(">>>>>%d : %s", i + 1, line);
// 		// free(line);
// 		i++;
// 	}
// 	// printf("\n");
// 	// system("leaks a.out");
// }
