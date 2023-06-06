/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 07:04:21 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/07 00:21:19 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_sub_process1(pid_t *pid, t_info *info)
{
	pid[0] = fork();
	if (pid[0] < 0)
		ft_perror_exit("fork");
	else if (pid[0] == 0)
	{
		if (dup2(info->infile_fd, STDIN_FILENO) == -1)
			ft_perror_exit("dup2");
		if (dup2(info->pipe[1], STDOUT_FILENO) == -1)
			ft_perror_exit("dup2");
		ft_closepipe(info->pipe);
		info->cmd1_split = ft_split(info->av[2], ' ');
		if (!info->cmd1_split)
			ft_perror_exit("malloc");
		ft_findcmd(info->path, info->cmd1_split[0], &info->pathcmd1);
		if (!info->pathcmd1)
			ft_perror_exit("no command");
		if (execve(info->pathcmd1, info->cmd1_split, info->envp) == -1)
			ft_perror_exit("execve");
	}
}

static void	ft_sub_process2(pid_t *pid, t_info *info)
{
	pid[1] = fork();
	if (pid[1] < 0)
		ft_perror_exit("fork");
	else if (pid[1] == 0)
	{
		if (dup2(info->outfile_fd, STDOUT_FILENO) == -1)
			ft_perror_exit("dup2");
		if (dup2(info->pipe[0], STDIN_FILENO) == -1)
			ft_perror_exit("dup2");
		ft_closepipe(info->pipe);
		info->cmd2_split = ft_split(info->av[3], ' ');
		if (!info->cmd2_split)
			ft_perror_exit("malloc");
		ft_findcmd(info->path, info->cmd2_split[0], &info->pathcmd2);
		if (!info->pathcmd2)
			ft_perror_exit("no command");
		if (execve(info->pathcmd2, info->cmd2_split, info->envp) == -1)
			ft_perror_exit("execve");
	}
}

void	ft_pipex(t_info *info)
{
	pid_t	pid[2];

	ft_sub_process1(pid, info);
	ft_sub_process2(pid, info);
	ft_closepipe(info->pipe);
	if (waitpid(pid[0], 0, 0) == -1)
		ft_perror_exit("waitpid");
	if (waitpid(pid[1], 0, 0) == -1)
		ft_perror_exit("waitpid");
}
