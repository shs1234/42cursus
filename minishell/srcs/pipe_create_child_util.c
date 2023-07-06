/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_create_child_util.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gibkim <gibkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:40:11 by gibkim            #+#    #+#             */
/*   Updated: 2023/07/04 15:57:33 by gibkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_access(t_pipe_cmd *cmd)
{
	if (cmd->output && access(cmd->output, F_OK | W_OK))
		print_error_exit(cmd->output, strerror(errno), 1);
	if (cmd->input && access(cmd->input, F_OK | R_OK))
		print_error_exit(cmd->input, strerror(errno), 1);
}

void	set_fd(t_pipe_cmd *cmd)
{
	if (cmd->output)
	{
		if (cmd->ofd_append)
			cmd->ofd = open(cmd->output, O_WRONLY | O_APPEND);
		else
			cmd->ofd = open(cmd->output, O_WRONLY | O_TRUNC);
		if (cmd->ofd < 0)
			error_exit();
	}
	if (cmd->input)
	{
		cmd->ifd = open(cmd->input, O_RDONLY);
		if (cmd->ifd < 0)
			error_exit();
		if (cmd->hd_file && !ft_strcmp(cmd->input, cmd->hd_file))
			if (unlink(cmd->input))
				error_exit();
	}
}

void	set_pipe_fd(t_pipe *pipe, t_pipe_cmd *cmd, int n)
{
	if (!cmd->output)
	{
		if (n == pipe->count - 1)
			cmd->ofd = STDOUT_FILENO;
		else
			cmd->ofd = pipe->fd[n][1];
	}
	if (!cmd->input)
	{
		if (n == 0 || !pipe->fd[n - 1])
			cmd->ifd = STDIN_FILENO;
		else
			cmd->ifd = pipe->fd[n - 1][0];
	}
}

void	pipe_redirect(t_pipe_cmd *cmd)
{
	if (cmd->ifd != 0)
	{
		if (dup2(cmd->ifd, STDIN_FILENO) < 0)
			error_exit();
	}
	if (cmd->ofd != 1)
	{
		if (dup2(cmd->ofd, STDOUT_FILENO) < 0)
			error_exit();
	}
}
