/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 07:51:45 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/27 04:44:34 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_closepipe(int *pipe)
{
	close(pipe[0]);
	close(pipe[1]);
}

void	ft_error(char *errmsg)
{
	ft_putstr_fd(errmsg, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	exit(errno);
}

char	*ft_pathjoin(char const *path, char const *cmd)
{
	char	*str;
	char	*str_start;

	if (!path || !cmd)
		return (0);
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

void	ft_findcmd(char **path, char *cmd, char **pathcmd)
{
	char	*str;

	while (*path)
	{
		str = ft_pathjoin(*path, cmd);
		if (!str)
			ft_error("join");
		if (!access(str, F_OK | X_OK))
		{
			*pathcmd = str;
			return ;
		}
		path++;
		free(str);
	}
	*pathcmd = cmd;
	ft_putstr_fd("command not found\n", 1);
}
