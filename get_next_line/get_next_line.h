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
#  define BUFFER_SIZE 10000000
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
char				*ft_strjoin(char *s1, char *s2, int pos);
size_t				ft_strlen(const char *s);
char				*ft_strdup(char *save, char *s1);
int					ft_has_newline(char *buf);

// void				ft_strcpy(char *dst, char *buf, int len);
// void				ft_lstadd_back(t_list **lst, t_list *new);
// t_list				*ft_lstnew(char *content);
// int					ft_has_newline(char *buf);
// t_list				*ft_lstlast(t_list *lst);
// void				ft_strlcat(char *dst, char *src, int end, int *len);
// int					ft_lstsize(t_list *lst);
// char				**ft_split(char const *s, char c);
// char				*ft_substr(char const *s, unsigned int start, int len);

#endif