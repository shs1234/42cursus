/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 03:20:53 by hoseoson          #+#    #+#             */
/*   Updated: 2023/07/04 16:26:58 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/srcs/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termcap.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MINISHELL "minishell$ "
# define TEMPLATE "/tmp/mstempfile"

# define ARGMAX 16384
# define TMAXLEN 1024
# define TMAXCOUNT 1024

# define STR 0
# define REDIR 1
# define PIPE 2

# define I_REDIR 1
# define O_REDIR 2
# define D_I_REDIR 3
# define D_O_REDIR 4

extern unsigned char	g_errno;

typedef struct s_data
{
	char				*line;
	char				**tokens;
	t_list				*envp;
	t_list				*lst;
}						t_data;

typedef struct s_token
{
	char				*str;
	int					meta;
}						t_token;

typedef struct s_split
{
	size_t				i;
	size_t				len;
	size_t				start;
	size_t				token_count;
	int					prev_meta;
}						t_split;

typedef struct s_pipe
{
	t_data				*data;
	char				**path;
	t_list				*cmd;
	int					count;
	int					**fd;
	pid_t				*pid;
}						t_pipe;

typedef struct s_pipe_cmd
{
	char				*input;
	int					ifd;
	int					ifd_heredoc;
	char				*output;
	int					ofd;
	int					ofd_append;
	char				*hd_file;
	char				**cmd;
	t_list				*redir;
}						t_pipe_cmd;

typedef struct s_pipe_redir
{
	char				*file;
	int					flag;
}						t_pipe_redir;

void					free_lines(char **lines);
void					clean_data(t_data *data);
void					error_exit(void);
char					*ft_pathjoin(char const *path, char const *cmd);
void					newaddback(t_list **lst, void *content);
int						ft_islong(const char *str);
void					print_error_exit(char *cmd, char *errmsg,
							int exit_code);
void					tokenjoin(t_data *data, t_token *token);
void					free_token(void *content);

void					signal_handler_sigint(int sig);
void					signal_handler_sigint_p(int sig);
void					signal_handler_sigquit(int sig);

void					echo(char **tokens);
void					cd(t_data *data, char **cmd);
void					pwd(void);
void					export(t_data *data, char **cmd);
void					unset(t_list **lst, char **key);
void					env(t_list *envp);
void					ms_exit(char **cmd, int cmd_count);

void					expansion(t_data *data, t_token *token);
char					*get_val(t_data *data, char *key);

int						tokenize(t_data *data);
void					tokenizer_quote(t_data *data, t_split *s);
void					tokenizer_str(t_data *data, t_split *s);
void					tokenizer_pipe(t_data *data, t_split *s);
void					tokenizer_redirection(t_data *data, t_split *s);

void					create_pipe(t_pipe *pipe);
void					check_access(t_pipe_cmd *cmd);
void					set_fd(t_pipe_cmd *cmd);
void					set_pipe_fd(t_pipe *pipe, t_pipe_cmd *cmd, int n);
void					pipe_redirect(t_pipe_cmd *cmd);
void					pipe_create_child(t_pipe *pipe);
void					pipe_let_cmd(t_pipe *pipe, t_pipe_cmd *cmd);
int						pipe_split_cmd(t_pipe *pipe);
void					read_heredoc(t_pipe_cmd *cmd, char *file);
int						create_output_file(t_pipe_cmd *cmd, char *file);
int						check_redir(t_pipe_cmd *cmd, t_pipe_redir *redir);
void					insert_input(t_pipe_cmd *cmd, char *input);
void					insert_output(t_pipe_cmd *cmd, char *output);
int						check_builtin(t_pipe *pipe, t_pipe_cmd *cmd);
int						pipe_line(t_data *data);
void					free_pipe(t_pipe *pipe);
void					set_child(t_pipe *pipe, int n);
int						isredirection(int i);
int						one_pipe(t_pipe *pipe);
void					close_fd_one(t_pipe_cmd *cmd);
void					restore_fd(int *fd);
void					one_pipe_dup(int *fd);
void					set_pipe_exit(int statloc);

int						is_closed(t_data *data);
int						valid_tokens(t_data *data);
int						invalid_input(t_data *data);
int						in_argmax(t_data *data);

char					*get_next_line(int fd);
void					ft_free(char **mem);
int						ft_has_newline(char *buf);
int						ft_ln_in_save(char **save, char **ret);
int						ft_ln_in_buf(char *buf, char **save, char **ret);

char					*ms_mktemp(char *template);

#endif
