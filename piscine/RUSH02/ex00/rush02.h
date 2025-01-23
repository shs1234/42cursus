/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:02:29 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/29 23:34:05 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *src, int len);
int		ft_in_charset(char c, char *charset);
char	**ft_split(char *str, char *charset);
char	*ft_read_dict(char *filename, int dict_len);
void	ft_count_dict_len(char *filename, int *len);
char	**ft_sep_split(char **split, int len);
void	ft_trim(char **split);
int		ft_atoi_len(char *str, int *len);
void	ft_make_dict(int ac, char **av, char ***key, char ***val);
void	convert_to_str(char *input, char **key, char **val);
void	ft_print_sep(int num, int floor, char **key, char **val);
void	ft_print_3int(int num, char **key, char **val);
void	ft_print(char *num, char **key, char **val);
int		*char_to_3int(char *arr, int *size);
void	ft_print_100(int num, char *out, char **key, char **val);
void	ft_print_2099(int num, char *out, char **key, char **val);
void	ft_print_1019(int num, char *out, char **key, char **val);
void	ft_print_0109(int num, char *out, char **key, char **val);
int		ft_is_printable(char *str);
int		ft_val_valid(char **key);
void	ft_zero_print(char **key, char **val);
void	ft_atoi_len2(char *str, int *len, int *start, int *end);
int		ft_main_error(int ac, char **av);
int		ft_main_error2(int *len);
int		ft_main_error3(int *len, char **key, char **val);
void	ft_free(char *str, char **key, char **val);

#endif