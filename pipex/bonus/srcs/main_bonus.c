/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 08:39:14 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/07 00:23:00 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_openfile(int ac, char **av, t_info *info)
{
	info->infile_fd = open(av[1], O_RDONLY);
	if (info->infile_fd < 0)
		ft_perror_exit("open");
	info->outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (info->outfile_fd < 0)
		ft_perror_exit("open");
}

static void	ft_openfile_heredoc(int ac, char **av, t_info *info)
{
	char	*line;

	info->infile_fd = open(".here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (info->infile_fd < 0)
		ft_perror_exit("open");
	info->outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (info->outfile_fd < 0)
		ft_perror_exit("open");
	while (1)
	{
		ft_print_heredoc(ac);
		line = get_next_line(0);
		if (!ft_strncmp(line, av[2], ft_strlen(av[2]))
			&& !line[ft_strlen(av[2]) + 1])
			break ;
		if (write(info->infile_fd, line, ft_strlen(line)) == -1)
			ft_perror_exit("write");
		free(line);
	}
	free(line);
	close(info->infile_fd);
	info->infile_fd = open(".here_doc", O_RDONLY);
}

static void	ft_info_init(int ac, char **av, char **envp, t_info *info)
{
	int	i;

	info->ac = ac;
	info->av = av;
	info->envp = envp;
	info->path = ft_findpath(envp);
	info->pid = malloc(sizeof(pid_t) * (ac - 3));
	info->pipe = malloc(sizeof(int *) * (ac - 4));
	info->cmd_split = malloc(sizeof(char **) * (ac - 3));
	info->pathcmd = malloc(sizeof(char *) * (ac - 3));
	if (!info->pipe || !info->cmd_split || !info->pathcmd || !info->pid)
		ft_perror_exit("malloc");
	i = 0;
	while (i < ac - 4)
	{
		info->pipe[i] = malloc(sizeof(int) * 2);
		if (!info->pipe[i])
			ft_perror_exit("malloc");
		if (pipe(info->pipe[i]) == -1)
			ft_perror_exit("pipe");
		i++;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_info	info;

	if (ac < 5)
		ft_error_exit("usage : ./pipex infile cmd1 ... cmdn outfile");
	if (!ft_strncmp(av[1], "here_doc", 8) && !av[1][8])
	{
		ft_openfile_heredoc(ac, av, &info);
		ac--;
		av++;
	}
	else
		ft_openfile(ac, av, &info);
	ft_info_init(ac, av, envp, &info);
	ft_pipex(&info);
	if (!ft_strncmp(av[0], "here_doc", 8) && !av[0][8])
	{
		if (unlink(".here_doc") == -1)
			ft_perror_exit("unlink");
	}
	return (0);
}
