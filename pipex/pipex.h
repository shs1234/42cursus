/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:55:12 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/08 13:19:35 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/wait.h>

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

void		ft_error(char *errmsg);
void		ft_closepipe(int *pipe);
char		*ft_pathjoin(char const *s1, char const *s2);
void		ft_findcmd(char **path, char *cmd, char **pathcmd);
void		ft_info_init(int ac, char **av, char **envp, t_info *info);
void		ft_pipex(int ac, char **av, char **envp);
void		ft_sub_process(pid_t *pid, t_info *info, char **envp);

#endif