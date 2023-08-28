/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:09:03 by hoseoson          #+#    #+#             */
/*   Updated: 2023/08/26 02:04:03 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define FD_MAX 256

int     ft_strlen(const char *s);
char	*get_next_line(int fd);
int		ft_has_newline(char *buf);
void	ft_free(char **mem);
int		ft_ln_in_save(char **save, char **ret);
int		ft_ln_in_buf(char *buf, char **save, char **ret);

#endif