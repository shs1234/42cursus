/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_read_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gibkim <gibkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:53:05 by gibkim            #+#    #+#             */
/*   Updated: 2023/07/03 19:58:06 by gibkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	heredoc_util(t_pipe_cmd *cmd)
{
	if (cmd->hd_file)
	{
		unlink(cmd->hd_file);
		free(cmd->hd_file);
		cmd->hd_file = NULL;
	}
	cmd->hd_file = ms_mktemp(TEMPLATE);
	insert_input(cmd, cmd->hd_file);
}

void	read_heredoc(t_pipe_cmd *cmd, char *eof)
{
	char	*temp;
	int		fd;

	heredoc_util(cmd);
	fd = open(cmd->input, O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
		error_exit();
	while (1)
	{
		write(1, "> ", 2);
		temp = get_next_line(STDIN_FILENO);
		if (!temp)
			break ;
		if (!ft_strncmp(temp, eof, ft_strlen(eof))
			&& temp[ft_strlen(eof)] == '\n')
		{
			free(temp);
			break ;
		}
		ft_putstr_fd(temp, fd);
		free(temp);
	}
	if (close(fd))
		error_exit();
}
