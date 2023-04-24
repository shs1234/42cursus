/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 07:04:21 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/25 07:58:04 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_info_init(char **av, char **envp, t_info *info)
{
	char	**path;

	if (pipe(info->pipe) == -1)
		ft_error("pipe");
	info->infile_fd = open(av[1], O_RDONLY);
	info->outfile_fd = open(av[4], O_WRONLY | O_CREAT, 0644);
	if (info->infile_fd < 0 || info->outfile_fd < 0)
		ft_error("fd");
	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	path = ft_split(&(*envp)[5], ':');
	info->cmd1_split = ft_split(av[2], ' ');
	info->cmd2_split = ft_split(av[3], ' ');
	if (!path || !info->cmd1_split || !info->cmd2_split)
		ft_error("split");
	ft_findcmd(path, info->cmd1_split[0], &info->pathcmd1);
	ft_findcmd(path, info->cmd2_split[0], &info->pathcmd2);
}

void	ft_sub_process(pid_t *pid, t_info *info, char **envp)
{
	pid[0] = fork();
	if (pid[0] < 0)
		ft_error("fork");
	if (pid[0] == 0)
	{
		if (dup2(info->infile_fd, STDIN_FILENO) == -1 ||
			dup2(info->pipe[1], STDOUT_FILENO) == -1)
			ft_error("dup");
		close(info->pipe[0]);
		close(info->pipe[1]);
		execve(info->pathcmd1, info->cmd1_split, envp);
	}
	pid[1] = fork();
	if (pid[1] < 0)
		ft_error("fork");
	if (pid[1] == 0)
	{
		if (dup2(info->outfile_fd, STDOUT_FILENO) == -1 ||
			dup2(info->pipe[0], STDIN_FILENO) == -1)
			ft_error("dup");
		close(info->pipe[1]);
		close(info->pipe[0]);
		execve(info->pathcmd2, info->cmd2_split, envp);
	}
}
void	ft_pipex(char **av, char **envp)
{
	t_info	info;
	pid_t	pid[2];

	ft_info_init(av, envp, &info);
	ft_sub_process(pid, &info, envp);
	close(info.pipe[0]);
	close(info.pipe[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
}
