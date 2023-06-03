/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 08:40:03 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/04 04:18:13 by hoseoson         ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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

void		ft_perror_exit(char *msg);
void		ft_error_exit(char *errmsg);
void		ft_close_pipe_all(t_info *info);
char		*ft_pathjoin(char const *s1, char const *s2);
void		ft_findcmd(char **path, char *cmd, char **pathcmd);
void		ft_pipex(t_info *info);

char		*get_next_line(int fd);
void		ft_free(char **mem);
int			ft_has_newline(char *buf);
int			ft_ln_in_save(char **save, char **ret);
int			ft_ln_in_buf(char *buf, char **save, char **ret);

#endif