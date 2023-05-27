/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:51:57 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/27 18:50:22 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_valid_outfile(int ac, char **av)
{
	char	*last_slash;
	char	*outfile;

	outfile = ft_strdup(av[ac - 1]);
	if (!outfile)
		ft_error("malloc");
	last_slash = ft_strrchr(outfile, '/');
	if (last_slash != NULL)
	{
		*last_slash = '\0';
		if (access(outfile, F_OK) == -1)
			ft_error("no directory");
	}
	free(outfile);
	return (1);
}

static int	ft_info_init(int ac, char **av, char **envp, t_info *info)
{
	char	**path;

	info->ac = ac;
	info->av = av;
	info->envp = envp;
	if (pipe(info->pipe) == -1)
		ft_error("pipe");
	info->infile_fd = open(av[1], O_RDONLY);
	info->outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (info->infile_fd < 0 || info->outfile_fd < 0)
		ft_error("fd");
	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	path = ft_split(&(*envp)[5], ':');
	info->cmd1_split = ft_split(av[2], ' ');
	info->cmd2_split = ft_split(av[3], ' ');
	if (!path || !info->cmd1_split || !info->cmd2_split)
		ft_error("malloc");
	ft_findcmd(path, info->cmd1_split[0], &info->pathcmd1);
	ft_findcmd(path, info->cmd2_split[0], &info->pathcmd2);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	t_info	info;

	if (ac != 5)
		ft_error("ac != 5");
	if (ft_valid_outfile(ac, av) && ft_info_init(ac, av, envp, &info))
		ft_pipex(&info);
	else
		return (1);
	return (0);
}
