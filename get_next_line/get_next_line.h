/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:36:17 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/28 12:32:21 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
char				*ft_strjoin(char *s1, const char *s2, int i);
int					ft_strlen(const char *s);
char				*ft_strdup(const char *s1, char *save);
int					ft_has_newline(char *buf);
void				ft_free(char **mem);
int					ft_ln_in_save(char **save, char **ret);
int					ft_ln_in_buf(char *buf, char **save, char **ret);

#endif