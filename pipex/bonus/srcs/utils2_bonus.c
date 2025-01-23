/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 04:59:24 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/05 06:56:03 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_print_heredoc(int ac)
{
	while (--ac > 4)
		ft_printf("pipex ");
	ft_printf("heredoc> ");
}

char	**ft_findpath(char **envp)
{
	char	**path;

	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH", 4))
			break ;
		envp++;
	}
	if (!*envp)
		ft_error_exit("no path");
	path = ft_split(&(*envp)[5], ':');
	if (!path)
		ft_perror_exit("malloc");
	return (path);
}
