/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:51:57 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/01 02:14:46 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_info_init(int ac, char **av, char **envp, t_info *info)
{
	info->ac = ac;
	info->av = av;
	info->envp = envp;
	if (pipe(info->pipe) == -1)
		ft_error("pipe");
	info->infile_fd = open(av[1], O_RDONLY);
	info->outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (info->infile_fd < 0 || info->outfile_fd < 0)
		ft_error("file");
	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	info->path = ft_split(&(*envp)[5], ':');
	if (!info->path)
		ft_error("malloc");
}

int	main(int ac, char **av, char **envp)
{
	t_info	info;

	if (ac != 5)
	{
		ft_printf("ac != 5\n");
		return (1);
	}
	ft_info_init(ac, av, envp, &info);
	ft_pipex(&info);
	return (0);
}
