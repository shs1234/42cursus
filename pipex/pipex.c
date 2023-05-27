/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 07:04:21 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/27 19:35:06 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_sub_process(pid_t *pid, t_info *info)
{
	pid[0] = fork();
	if (pid[0] < 0)
		ft_error("fork");
	else if (pid[0] == 0)
	{
		dup2(info->infile_fd, STDIN_FILENO);
		dup2(info->pipe[1], STDOUT_FILENO);
		ft_closepipe(info->pipe);
		if (execve(info->pathcmd1, info->cmd1_split, info->envp) == -1)
			exit(errno);
	}
	pid[1] = fork();
	if (pid[1] < 0)
		ft_error("fork");
	else if (pid[1] == 0)
	{
		dup2(info->outfile_fd, STDOUT_FILENO);
		dup2(info->pipe[0], STDIN_FILENO);
		ft_closepipe(info->pipe);
		// if (!ft_strchr(info->pathcmd2, '/'))
		// 	exit(127);
		if (execve(info->pathcmd2, info->cmd2_split, info->envp) == -1)
			ft_error("exec");
		// exit(errno);
	}
}

void	ft_pipex(t_info *info)
{
	pid_t	pid[2];
	int		status;

	ft_sub_process(pid, info);
	ft_closepipe(info->pipe);
	waitpid(pid[1], &status, 0);
	exit(WEXITSTATUS(status));
}
