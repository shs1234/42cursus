/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 08:39:14 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/26 21:54:04 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_info_init(int ac, char **av, char **envp, t_info *info)
{
	char	**path;
	int		i;

	info->infile_fd = open(av[1], O_RDONLY);
	info->outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT, 0644);
	if (info->infile_fd < 0 || info->outfile_fd < 0)
		ft_error("fd");
	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	path = ft_split(&(*envp)[5], ':');
	info->pipe = malloc(sizeof(int *) * (ac - 4));
	info->cmd_split = malloc(sizeof(char **) * (ac - 3));
	info->pathcmd = malloc(sizeof(char *) * (ac - 3));
	if (!info->pipe || !info->cmd_split || !path || !info->pathcmd)
		ft_error("malloc");
	i = 0;
	while (i < ac - 4)
	{
		info->cmd_split[i] = ft_split(av[2 + i], ' ');
		info->pipe[i] = malloc(sizeof(int) * 2);
		if (!info->cmd_split[i] || !info->pipe[i])
			ft_error("malloc");
		if (pipe(info->pipe[i]) == -1)
			ft_error("pipe");
		ft_findcmd(path, info->cmd_split[i][0], &info->pathcmd[i]);
		i++;
	}
	info->cmd_split[i] = ft_split(av[2 + i], ' ');
	if (!info->cmd_split[i])
		ft_error("malloc");
	ft_findcmd(path, info->cmd_split[i][0], &info->pathcmd[i]);
}
void	ft_sub_process1(int i, pid_t *pid, t_info *info, char **envp)
{
	pid[i] = fork();
	if (pid[i] < 0)
		ft_error("fork");
	if (pid[i] == 0)
	{
		if (dup2(info->infile_fd, STDIN_FILENO) == -1 ||
			dup2(info->pipe[i][1], STDOUT_FILENO) == -1)
			ft_error("dup1");
		close(info->infile_fd);
		close(info->pipe[i][1]);
		execve(info->pathcmd[i], info->cmd_split[i], envp);
	}
}
void	ft_sub_process2(int i, pid_t *pid, t_info *info, char **envp)
{
	pid[i] = fork();
	if (pid[i] < 0)
		ft_error("fork");
	if (pid[i] == 0)
	{
		if (dup2(info->pipe[i][1], STDOUT_FILENO) == -1)
			ft_error("dup2");
		if (dup2(info->pipe[i - 1][0], STDIN_FILENO) == -1)
			ft_error("dup4");
		close(info->pipe[i][1]);
		close(info->pipe[i - 1][0]);
		execve(info->pathcmd[i], info->cmd_split[i], envp);
	}
}
void	ft_sub_process3(int i, pid_t *pid, t_info *info, char **envp)
{
	pid[i] = fork();
	if (pid[i] < 0)
		ft_error("fork");
	if (pid[i] == 0)
	{
		if (dup2(info->pipe[i][1], STDIN_FILENO) == -1 ||
			dup2(info->outfile_fd, STDOUT_FILENO) == -1)
			ft_error("dup3");
		close(info->pipe[i][1]);
		close(info->outfile_fd);
		execve(info->pathcmd[i], info->cmd_split[i], envp);
	}
}

void	ft_pipex(int ac, char **av, char **envp)
{
	t_info	info;
	pid_t	*pid;
	int		i;

	pid = malloc(sizeof(pid_t) * (ac - 3));
	if (!pid)
		ft_error("malloc");
	ft_info_init(ac, av, envp, &info);
	i = 0;
	while (i < ac - 3)
	{
		if (i == 0)
			ft_sub_process1(i, pid, &info, envp);
		else if (i == ac - 4)
			ft_sub_process3(i, pid, &info, envp);
		else
			ft_sub_process2(i, pid, &info, envp);
		if (i < ac - 4)
			ft_closepipe(info.pipe[i]);
		waitpid(pid[i], NULL, 0);
		i++;
	}
}

int	main(int ac, char **av, char **envp)
{
	ft_pipex(ac, av, envp);
	return (0);
}