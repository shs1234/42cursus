/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 07:04:21 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/30 12:04:03 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_info_init(char **av, char **envp, t_info *info)
{
	char	**path;

	if (pipe(info->pipe) == -1)
		ft_error(strerror(errno));
	info->infile_fd = open(av[1], O_RDONLY);
	info->outfile_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (info->infile_fd < 0 || info->outfile_fd < 0)
		ft_printf("%s", "No such file or directory");
	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	path = ft_split(&(*envp)[5], ':');
	info->cmd1_split = ft_split(av[2], ' ');
	info->cmd2_split = ft_split(av[3], ' ');
	if (!path || !info->cmd1_split || !info->cmd2_split)
		ft_error(strerror(errno));
	ft_findcmd(path, info->cmd1_split[0], &info->pathcmd1);
	ft_findcmd(path, info->cmd2_split[0], &info->pathcmd2);
}

void	ft_sub_process(pid_t *pid, t_info *info, char **envp)
{
	pid[0] = fork();
	if (pid[0] < 0)
		ft_error(strerror(errno));
	if (pid[0] == 0)
	{
		dup2(info->infile_fd, STDIN_FILENO);
		dup2(info->pipe[1], STDOUT_FILENO);
		ft_closepipe(info->pipe);
		execve(info->pathcmd1, info->cmd1_split, envp);
		exit(0);
	}
	pid[1] = fork();
	if (pid[1] < 0)
		ft_error(strerror(errno));
	if (pid[1] == 0)
	{
		dup2(info->outfile_fd, STDOUT_FILENO);
		dup2(info->pipe[0], STDIN_FILENO);
		ft_closepipe(info->pipe);
		if (execve(info->pathcmd2, info->cmd2_split, envp) == -1)
			exit(127);
	}
}

void	ft_pipex(char **av, char **envp)
{
	t_info	info;
	pid_t	pid[2];
	int		status;

	ft_info_init(av, envp, &info);
	ft_sub_process(pid, &info, envp);
	ft_closepipe(info.pipe);
	waitpid(pid[1], &status, 0);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
}
