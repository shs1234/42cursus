/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:35:18 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/03 17:21:29 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_buflst {
	struct s_buflst	*next;
	ssize_t			read_size;
	ssize_t			buf_i;
	char			*buf;
	int				fd;
}	t_buflst;

// get_next_line_utils.c
void		s_join(char **dst, char *src, ssize_t dst_len, ssize_t src_len);
t_buflst	*isfd(t_buflst *buflst, int fd);
t_buflst	*lstnew(int fd);
void		lstadd_back(t_buflst **lst, t_buflst *n);
void		lstdelone(t_buflst **lst, t_buflst *lst_copy, int fd);

#endif
