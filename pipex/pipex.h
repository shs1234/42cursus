/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:55:12 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/23 14:55:51 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <wait.h>

typedef struct s_info
{
	int		infile_fd;
	int		outfile_fd;
	int		pipe[2];
	char	**cmd1_split;
	char	**cmd2_split;
	char	*pathcmd1;
	char	*pathcmd2;
}			t_info;

#endif