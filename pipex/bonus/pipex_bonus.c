/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:14:42 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/30 00:27:51 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_close_pipe_all(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->ac - 4)
	{
		close(info->pipe[i][0]);
		close(info->pipe[i][1]);
		i++;
	}
}

static void	ft_sub_process1(int i, t_info *info)
{
	info->pid[i] = fork();
	if (info->pid[i] < 0)
		ft_error("fork");
	if (info->pid[i] == 0)
	{
		dup2(info->infile_fd, STDIN_FILENO);
		dup2(info->pipe[i][1], STDOUT_FILENO);
		ft_close_pipe_all(info);
		info->cmd_split[i] = ft_split(info->av[2 + i], ' ');
		if (!info->cmd_split[i])
			ft_error("malloc");
		ft_findcmd(info->path, info->cmd_split[i][0], &info->pathcmd[i]);
		if (!info->pathcmd[i])
			ft_error("no command");
		execve(info->pathcmd[i], info->cmd_split[i], info->envp);
	}
}

static void	ft_sub_process2(int i, t_info *info)
{
	info->pid[i] = fork();
	if (info->pid[i] < 0)
		ft_error("fork");
	if (info->pid[i] == 0)
	{
		dup2(info->pipe[i - 1][0], STDIN_FILENO);
		dup2(info->pipe[i][1], STDOUT_FILENO);
		ft_close_pipe_all(info);
		info->cmd_split[i] = ft_split(info->av[2 + i], ' ');
		if (!info->cmd_split[i])
			ft_error("malloc");
		ft_findcmd(info->path, info->cmd_split[i][0], &info->pathcmd[i]);
		if (!info->pathcmd[i])
			ft_error("no command");
		execve(info->pathcmd[i], info->cmd_split[i], info->envp);
	}
}

static void	ft_sub_process3(int i, t_info *info)
{
	info->pid[i] = fork();
	if (info->pid[i] < 0)
		ft_error("fork");
	if (info->pid[i] == 0)
	{
		dup2(info->pipe[i - 1][0], STDIN_FILENO);
		dup2(info->outfile_fd, STDOUT_FILENO);
		ft_close_pipe_all(info);
		info->cmd_split[i] = ft_split(info->av[2 + i], ' ');
		if (!info->cmd_split[i])
			ft_error("malloc");
		ft_findcmd(info->path, info->cmd_split[i][0], &info->pathcmd[i]);
		if (!info->pathcmd[i])
			ft_error("no command");
		execve(info->pathcmd[i], info->cmd_split[i], info->envp);
	}
}

void	ft_pipex(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->ac - 3)
	{
		if (i == 0)
			ft_sub_process1(i, info);
		else if (i == info->ac - 4)
			ft_sub_process3(i, info);
		else
			ft_sub_process2(i, info);
		i++;
	}
	ft_close_pipe_all(info);
	i = 0;
	while (i < info->ac - 3)
	{
		waitpid(info->pid[i], 0, 0);
		i++;
	}
}
