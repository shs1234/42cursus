/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 07:04:21 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/30 00:26:08 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_sub_process1(pid_t *pid, t_info *info)
{
	pid[0] = fork();
	if (pid[0] < 0)
		ft_error("fork");
	else if (pid[0] == 0)
	{
		dup2(info->infile_fd, STDIN_FILENO);
		dup2(info->pipe[1], STDOUT_FILENO);
		ft_closepipe(info->pipe);
		info->cmd1_split = ft_split(info->av[2], ' ');
		if (!info->cmd1_split)
			ft_error("malloc");
		ft_findcmd(info->path, info->cmd1_split[0], &info->pathcmd1);
		if (!info->pathcmd1)
			ft_error("no command");
		execve(info->pathcmd1, info->cmd1_split, info->envp);
	}
}

static void	ft_sub_process2(pid_t *pid, t_info *info)
{
	pid[1] = fork();
	if (pid[1] < 0)
		ft_error("fork");
	else if (pid[1] == 0)
	{
		dup2(info->outfile_fd, STDOUT_FILENO);
		dup2(info->pipe[0], STDIN_FILENO);
		ft_closepipe(info->pipe);
		info->cmd2_split = ft_split(info->av[3], ' ');
		if (!info->cmd2_split)
			ft_error("malloc");
		ft_findcmd(info->path, info->cmd2_split[0], &info->pathcmd2);
		if (!info->pathcmd2)
			ft_error("no command");
		execve(info->pathcmd2, info->cmd2_split, info->envp);
	}
}

void	ft_pipex(t_info *info)
{
	pid_t	pid[2];

	ft_sub_process1(pid, info);
	ft_sub_process2(pid, info);
	ft_closepipe(info->pipe);
	waitpid(pid[0], 0, 0);
	waitpid(pid[1], 0, 0);
}
