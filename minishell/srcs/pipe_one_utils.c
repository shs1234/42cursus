/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_one_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gibkim <gibkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:11:55 by gibkim            #+#    #+#             */
/*   Updated: 2023/07/04 15:48:22 by gibkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_access_one(t_pipe_cmd *cmd)
{
	if (cmd->output && access(cmd->output, F_OK | W_OK))
	{
		print_error_exit(cmd->output, strerror(errno), -1);
		return (1);
	}
	if (cmd->input && access(cmd->input, F_OK | R_OK))
	{
		print_error_exit(cmd->input, strerror(errno), -1);
		return (1);
	}
	return (0);
}

static int	is_builtin(t_pipe_cmd *cmd)
{
	if (!cmd->cmd[0])
		return (1);
	if (!ft_strcmp(cmd->cmd[0], "echo"))
		return (1);
	else if (!ft_strcmp(cmd->cmd[0], "cd"))
		return (1);
	else if (!ft_strcmp(cmd->cmd[0], "pwd"))
		return (1);
	else if (!ft_strcmp(cmd->cmd[0], "export"))
		return (1);
	else if (!ft_strcmp(cmd->cmd[0], "unset"))
		return (1);
	else if (!ft_strcmp(cmd->cmd[0], "env"))
		return (1);
	else if (!ft_strcmp(cmd->cmd[0], "exit"))
		return (1);
	return (0);
}

static int	one_pipe_check_redir(t_pipe_cmd *cmd, int *fd)
{
	t_list	*temp;

	temp = cmd->redir;
	while (temp)
	{
		if (check_redir(cmd, temp->content) || check_access_one(cmd))
		{
			g_errno = 1;
			return (1);
		}
		temp = temp->next;
	}
	if (cmd->redir)
	{
		cmd->ifd = STDIN_FILENO;
		cmd->ofd = STDOUT_FILENO;
		set_fd(cmd);
		one_pipe_dup(fd);
		pipe_redirect(cmd);
		close_fd_one(cmd);
	}
	return (0);
}

int	one_pipe(t_pipe *pipe)
{
	int	statloc;
	int	fd[2];

	if (!is_builtin(pipe->cmd->content))
	{
		pipe_create_child(pipe);
		if (waitpid(pipe->pid[0], &statloc, WUNTRACED) == -1)
			error_exit();
		set_pipe_exit(statloc);
		free_pipe(pipe);
		return (0);
	}
	if (one_pipe_check_redir(pipe->cmd->content, fd))
		return (1);
	check_builtin(pipe, pipe->cmd->content);
	if (((t_pipe_cmd *)pipe->cmd->content)->redir)
		restore_fd(fd);
	free_pipe(pipe);
	return (0);
}
