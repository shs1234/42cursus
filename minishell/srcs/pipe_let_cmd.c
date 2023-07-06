/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_let_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gibkim <gibkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:42:13 by gibkim            #+#    #+#             */
/*   Updated: 2023/07/04 16:00:07 by gibkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**lsttoarr(t_list *list)
{
	int		i;
	int		len;
	char	**temp;

	len = ft_lstsize(list);
	temp = (char **)malloc(sizeof(char *) * (len + 1));
	if (!temp)
		error_exit();
	i = 0;
	while (i < len)
	{
		temp[i] = (char *)list->content;
		list = list->next;
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

static void	file_chk(char *filename)
{
	struct stat	filestat;

	if (!ft_strchr(filename, '/'))
		return ;
	if (stat(filename, &filestat) < 0 && ft_strchr(filename, '/'))
		print_error_exit(filename, "No such file or directory", 127);
	if (S_ISDIR(filestat.st_mode))
		print_error_exit(filename, "is a directory", 126);
	if (!(filestat.st_mode & S_IXUSR))
		print_error_exit(filename, "Permission denied", 126);
}

static int	findpath(char **path_list, char *cmd, char **path)
{
	char	*str;

	file_chk(cmd);
	if (!path_list || !access(cmd, F_OK | X_OK))
	{
		*path = NULL;
		return (1);
	}
	while (*path_list)
	{
		str = ft_pathjoin(*path_list, cmd);
		if (!str)
			error_exit();
		if (!access(str, F_OK | X_OK))
		{
			*path = *path_list;
			return (1);
		}
		path_list++;
		free(str);
	}
	return (0);
}

void	pipe_let_cmd(t_pipe *pipe, t_pipe_cmd *cmd)
{
	char	*path;
	char	*pathcmd;

	path = NULL;
	if (cmd->cmd[0][0] && findpath(pipe->path, cmd->cmd[0], &path))
	{
		if (path)
			pathcmd = ft_pathjoin(path, cmd->cmd[0]);
		else
			pathcmd = ft_strdup(cmd->cmd[0]);
		if (!pathcmd)
			error_exit();
		if (execve(pathcmd, cmd->cmd, lsttoarr(pipe->data->envp)) < 0
			&& errno != 13)
			print_error_exit(cmd->cmd[0], strerror(errno), 126);
	}
	print_error_exit(cmd->cmd[0], "command not found", 127);
}
