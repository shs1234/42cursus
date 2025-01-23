/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 07:51:45 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/07 00:21:29 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_closepipe(int *pipe)
{
	if (close(pipe[0]) == -1)
		ft_perror_exit("close");
	if (close(pipe[1]) == -1)
		ft_perror_exit("close");
}

void	ft_perror_exit(char *errmsg)
{
	perror(errmsg);
	exit(1);
}

void	ft_error_exit(char *errmsg)
{
	ft_putendl_fd(errmsg, STDERR_FILENO);
	exit(1);
}

char	*ft_pathjoin(char const *path, char const *cmd)
{
	char	*str;
	char	*str_start;

	if (!path || !cmd)
		ft_error_exit("pathjoin: path or cmd is NULL");
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
			ft_perror_exit("malloc");
		if (!access(str, F_OK | X_OK))
		{
			*pathcmd = str;
			return ;
		}
		path++;
		free(str);
	}
	if (!access(cmd, F_OK | X_OK))
	{
		*pathcmd = cmd;
		return ;
	}
	*pathcmd = NULL;
}
