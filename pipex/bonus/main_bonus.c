/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 08:39:14 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/08 17:28:35 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	ft_valid_outfile(int ac, char **av)
{
	char	*last_slash;
	char	*outfile;

	outfile = ft_strdup(av[ac - 1]);
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
	if (ac >= 5)
	{
		if (!ft_valid_outfile(ac, av))
			return (1);
		ft_pipex(ac, av, envp);
	}
	else
		return (1);
	return (0);
}