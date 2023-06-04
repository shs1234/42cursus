/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:14:42 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/05 02:52:24 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_sub_process1(int i, t_info *info)
{
	info->pid[i] = fork();
	if (info->pid[i] < 0)
		ft_perror_exit("fork");
	if (info->pid[i] == 0)
	{
		if (dup2(info->infile_fd, STDIN_FILENO) == -1)
			ft_perror_exit("dup2");
		if (dup2(info->pipe[i][1], STDOUT_FILENO) == -1)
			ft_perror_exit("dup2");
		ft_close_pipe_all(info);
		info->cmd_split[i] = ft_split(info->av[2 + i], ' ');
		if (!info->cmd_split[i])
			ft_perror_exit("malloc");
		ft_findcmd(info->path, info->cmd_split[i][0], &info->pathcmd[i]);
		if (!info->pathcmd[i])
			ft_perror_exit("no command");
		if (execve(info->pathcmd[i], info->cmd_split[i], info->envp) == -1)
			ft_perror_exit("execve");
	}
}

static void	ft_sub_process2(int i, t_info *info)
{
	info->pid[i] = fork();
	if (info->pid[i] < 0)
		ft_perror_exit("fork");
	if (info->pid[i] == 0)
	{
		if (dup2(info->pipe[i - 1][0], STDIN_FILENO) == -1)
			ft_perror_exit("dup2");
		if (dup2(info->pipe[i][1], STDOUT_FILENO) == -1)
			ft_perror_exit("dup2");
		ft_close_pipe_all(info);
		info->cmd_split[i] = ft_split(info->av[2 + i], ' ');
		if (!info->cmd_split[i])
			ft_perror_exit("malloc");
		ft_findcmd(info->path, info->cmd_split[i][0], &info->pathcmd[i]);
		if (!info->pathcmd[i])
			ft_perror_exit("no command");
		if (execve(info->pathcmd[i], info->cmd_split[i], info->envp) == -1)
			ft_perror_exit("execve");
	}
}

static void	ft_sub_process3(int i, t_info *info)
{
	info->pid[i] = fork();
	if (info->pid[i] < 0)
		ft_perror_exit("fork");
	if (info->pid[i] == 0)
	{
		if (dup2(info->pipe[i - 1][0], STDIN_FILENO) == -1)
			ft_perror_exit("dup2");
		if (dup2(info->outfile_fd, STDOUT_FILENO) == -1)
			ft_perror_exit("dup2");
		ft_close_pipe_all(info);
		info->cmd_split[i] = ft_split(info->av[2 + i], ' ');
		if (!info->cmd_split[i])
			ft_perror_exit("malloc");
		ft_findcmd(info->path, info->cmd_split[i][0], &info->pathcmd[i]);
		if (!info->pathcmd[i])
			ft_perror_exit("no command");
		if (execve(info->pathcmd[i], info->cmd_split[i], info->envp) == -1)
			ft_perror_exit("execve");
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
		if (waitpid(info->pid[i], 0, 0) == -1)
			ft_perror_exit("waitpid");
		i++;
	}
}
