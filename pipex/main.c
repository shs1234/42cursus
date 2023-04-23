/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:51:57 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/23 15:56:25 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_findcmd(char **path, char *cmd, char **pathcmd)
{
	char	*str;

	while (*path)
	{
		str = ft_strjoin(ft_strjoin(*path, "/"), cmd);
		if (!access(str, F_OK && X_OK))
		{
			*pathcmd = str;
			return ;
		}
		path++;
	}
    ft_putstr_fd("command not found\n", STDOUT_FILENO);
    exit(EXIT_FAILURE);
}

void	ft_info_init(int ac, char **av, char **envp, t_info *info)
{
	char	**path;
	char	*cmd;

	if (pipe(info->pipe) == -1)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	info->infile_fd = open(av[1], O_RDONLY);
	info->outfile_fd = open(av[4], O_WRONLY);
	if (info->infile_fd < 0 || info->outfile_fd < 0)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	path = ft_split(&(*envp)[5], ':');
    info->cmd1_split = ft_split(av[2], ' ');
    info->cmd2_split = ft_split(av[3], ' ');
	ft_findcmd(path, info->cmd1_split[0], &info->pathcmd1);
	ft_findcmd(path, info->cmd2_split[0], &info->pathcmd2);
}

void	ft_pipex(int ac, char **av, char **envp)
{
	t_info	info;
	pid_t	pid;

	ft_info_init(ac, av, envp, &info);
	pid = fork();
	if (pid < 0)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		dup2(info.infile_fd, STDIN_FILENO);
		dup2(info.pipe[1], STDOUT_FILENO);
		close(info.pipe[0]);
		execve(info.pathcmd1, info.cmd1_split, envp);
	}
	else if (pid > 0)
	{
		dup2(info.outfile_fd, STDOUT_FILENO);
		dup2(info.pipe[0], STDIN_FILENO);
		close(info.pipe[1]);
		execve(info.pathcmd2, info.cmd2_split, envp);
	}
}

int	main(int ac, char **av, char **envp)
{
	if (ac == 5)
		ft_pipex(ac, av, envp);
	return (0);
}
