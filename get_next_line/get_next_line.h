/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:36:17 by hoseoson          #+#    #+#             */
/*   Updated: 2023/03/27 02:53:46 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

typedef struct		s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
void	ft_strcpy(char *dst, char *buf, int len);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(char *content);
int		ft_has_newline(char *buf);
t_list	*ft_lstlast(t_list *lst);
void	ft_strlcat(char *dst, char *src, int end, int *len);
int		ft_lstsize(t_list *lst);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, int len);

#endif