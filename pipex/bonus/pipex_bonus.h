/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 08:40:03 by hoseoson          #+#    #+#             */
/*   Updated: 2023/05/29 21:52:35 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/wait.h>

typedef struct s_info
{
	int		ac;
	char	**av;
	char	**envp;
	char	**path;
	pid_t	*pid;
	int		infile_fd;
	int		outfile_fd;
	int		**pipe;
	char	***cmd_split;
	char	**pathcmd;
}			t_info;

void		ft_error(char *msg);
char		*ft_pathjoin(char const *s1, char const *s2);
void		ft_findcmd(char **path, char *cmd, char **pathcmd);
void		ft_pipex(t_info *info);
void		ft_closepipe(int *pipe);

#endif