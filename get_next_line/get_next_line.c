/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:35:50 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/28 13:06:53 by hoseoson         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	static char	*save;
	char		buf[BUFFER_SIZE + 1];
	int			len;
	char		*ret;
	int			pos;

	ret = 0;
	if (fd == 1 || fd == 2 || fd < 0 || BUFFER_SIZE < 1)
		return (0);
	while (1)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1) // ㅇㅗㄹㅠ
			return (NULL);
		else if (len == 0) // ㅁㅏ지막, save가 있으면 그거 리턴
		{
			if (ret)
				return (ret);
			if (save)
			{
				pos = ft_has_newline(save);
				ret = ft_strjoin(ret, save, pos);
				if (save[pos + 1])
					save = ft_strdup(save, &save[pos + 1]);
			}
			break ;
		}
		else // 값 불러왔을때
		{
			buf[len] = '\0';
			if (save)
			{
				pos = ft_has_newline(save);
				ret = ft_strjoin(ret, save, pos);
				if (save[pos + 1])
					save = ft_strdup(save, &save[pos + 1]);
			}
			pos = ft_has_newline(buf);
			if (pos >= 0) // 개행이 있을 경우
			{
				ret = ft_strjoin(ret, buf, pos);
				if (buf[pos + 1])
					save = ft_strdup(save, &buf[pos + 1]);
				break ;
			}
			else // pos -1 개행 없을 경우. 개행계속 붙이기만 함
				ret = ft_strjoin(ret, buf, pos);
		}
	}
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
