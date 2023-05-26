/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:51:57 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/27 03:04:48 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_valid_outfile(int ac, char **av)
{
	char	*last_slash;
	char	*outfile;

	outfile = ft_strdup(av[ac - 1]);
	if (!outfile)
		return (0);
	last_slash = ft_strrchr(outfile, '/');
	if (last_slash != NULL)
	{
		*last_slash = '\0';
		if (access(outfile, F_OK) == -1)
		{
			free(outfile);
			ft_printf("directory\n");
			return (0);
		}
	}
	free(outfile);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	if (ac == 5 && ft_valid_outfile(ac, av))
		ft_pipex(ac, av, envp);
	else
		return (1);
	return (0);
}
