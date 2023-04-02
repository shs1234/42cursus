/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:09:03 by hoseoson          #+#    #+#             */
/*   Updated: 2023/04/03 00:21:22 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// # define FD_MAX 4096

typedef struct s_list
{
	int				fd;
	char			*save;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
char				*ft_strjoin(char *s1, const char *s2, int i);
int					ft_strlen(const char *s);
char				*ft_strdup(const char *s1, char *save);
int					ft_has_newline(char *buf);
void				ft_free(char **mem);
int					ft_ln_in_save(char **save, char **ret, t_list *head);
int					ft_ln_in_buf(char *buf, char **save, char **ret,
						t_list *head);
void				ft_freelist(t_list *head);
t_list				*ft_findfd(t_list **head, int fd);

#endif