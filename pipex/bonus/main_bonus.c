/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 08:39:14 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/01 02:15:11 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_openfile(int ac, char **av, t_info *info)
{
	info->infile_fd = open(av[1], O_RDONLY);
	info->outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (info->infile_fd < 0 || info->outfile_fd < 0)
		ft_error("open");
}

static void	ft_info_init(int ac, char **av, char **envp, t_info *info)
{
	int	i;

	info->ac = ac;
	info->av = av;
	info->envp = envp;
	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	info->path = ft_split(&(*envp)[5], ':');
	info->pid = malloc(sizeof(pid_t) * (info->ac - 3));
	info->pipe = malloc(sizeof(int *) * (ac - 4));
	info->cmd_split = malloc(sizeof(char **) * (ac - 3));
	info->pathcmd = malloc(sizeof(char *) * (ac - 3));
	if (!info->pipe || !info->cmd_split || !info->path || !info->pathcmd
		|| !info->pid)
		ft_error("malloc");
	i = 0;
	while (i < ac - 4)
	{
		info->pipe[i] = malloc(sizeof(int) * 2);
		if (!info->pipe[i])
			ft_error("malloc");
		if (pipe(info->pipe[i]) == -1)
			ft_error("pipe");
		i++;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_info	info;

	if (ac < 5)
	{
		ft_printf("ac < 5\n");
		return (1);
	}
	ft_openfile(ac, av, &info);
	ft_info_init(ac, av, envp, &info);
	ft_pipex(&info);
	return (0);
}
