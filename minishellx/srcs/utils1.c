/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gibkim <gibkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:03:00 by hoseoson          #+#    #+#             */
/*   Updated: 2023/07/04 15:59:36 by gibkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
		free(lines[i++]);
	free(lines);
}

void	free_token(void *content)
{
	t_token	*temp;

	temp = content;
	free(temp->str);
	free(temp);
}

void	clean_data(t_data *data)
{
	if (data->line)
		free(data->line);
	if (data->lst)
		ft_lstclear(&data->lst, free_token);
	if (data->tokens)
		free_lines(data->tokens);
}

void	error_exit(void)
{
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	exit(1);
}

char	*ft_pathjoin(char const *path, char const *cmd)
{
	char	*str;
	char	*str_start;

	if (!path)
		return ((char *)cmd);
	str = malloc(ft_strlen(path) + ft_strlen(cmd) + 2);
	if (!str)
		return (0);
	str_start = str;
	while (*path)
		*str++ = *path++;
	*str++ = '/';
	while (*cmd)
		*str++ = *cmd++;
	*str = '\0';
	return (str_start);
}
