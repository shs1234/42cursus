/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:14:42 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/08 17:45:26 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_info_init(int ac, char **av, char **envp, t_info *info)
{
	char	**path;
	int		i;

	info->ac = ac;
	info->infile_fd = open(av[1], O_RDONLY);
	info->outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (info->infile_fd < 0 || info->outfile_fd < 0)
		ft_printf("%s", "No such file or directory");
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
		info->pipe[i] = malloc(sizeof(int) * 2);
		info->cmd_split[i] = ft_split(av[2 + i], ' ');
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

static void	ft_sub_process1(int i, pid_t *pid, t_info *info, char **envp)
{
	pid[i] = fork();
	if (pid[i] < 0)
		ft_error(strerror(errno));
	if (pid[i] == 0)
	{
		dup2(info->infile_fd, STDIN_FILENO);
		dup2(info->pipe[i][1], STDOUT_FILENO);
		ft_close_pipe_all(info);
		if (execve(info->pathcmd[i], info->cmd_split[i], envp) == -1)
			exit(errno);
	}
}
static void	ft_sub_process2(int i, pid_t *pid, t_info *info, char **envp)
{
	pid[i] = fork();
	if (pid[i] < 0)
		ft_error(strerror(errno));
	if (pid[i] == 0)
	{
		dup2(info->pipe[i - 1][0], STDIN_FILENO);
		dup2(info->pipe[i][1], STDOUT_FILENO);
		ft_close_pipe_all(info);
		if (execve(info->pathcmd[i], info->cmd_split[i], envp) == -1)
			exit(errno);
	}
}
static void	ft_sub_process3(int i, pid_t *pid, t_info *info, char **envp)
{
	pid[i] = fork();
	if (pid[i] < 0)
		ft_error(strerror(errno));
	if (pid[i] == 0)
	{
		dup2(info->pipe[i - 1][0], STDIN_FILENO);
		dup2(info->outfile_fd, STDOUT_FILENO);
		ft_close_pipe_all(info);
		if (!ft_strchr(info->pathcmd[i], '/'))
			exit(127);
		if (execve(info->pathcmd[i], info->cmd_split[i], envp) == -1)
			exit(errno);
	}
}

void	ft_pipex(int ac, char **av, char **envp)
{
	t_info	info;
	pid_t	*pid;
	int		i;
	int		status;

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
		i++;
	}
	ft_close_pipe_all(&info);
	waitpid(pid[i - 1], &status, 0);
	exit(WEXITSTATUS(status));
}
