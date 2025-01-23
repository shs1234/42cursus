/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_create_child.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:52:28 by gibkim            #+#    #+#             */
/*   Updated: 2023/07/04 16:15:42 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	close_fd(t_pipe *pipe)
{
	int	i;

	i = 0;
	while (i < pipe->count - 1)
	{
		if (close(pipe->fd[i][0]) < 0)
			error_exit();
		if (close(pipe->fd[i][1]) < 0)
			error_exit();
		i++;
	}
}

int	check_builtin(t_pipe *pipe, t_pipe_cmd *cmd)
{
	if (!cmd->cmd[0])
		return (1);
	if (!ft_strcmp(cmd->cmd[0], "echo"))
		echo(cmd->cmd);
	else if (!ft_strcmp(cmd->cmd[0], "cd"))
		cd(pipe->data, cmd->cmd);
	else if (!ft_strcmp(cmd->cmd[0], "pwd"))
		pwd();
	else if (!ft_strcmp(cmd->cmd[0], "export"))
		export(pipe->data, cmd->cmd);
	else if (!ft_strcmp(cmd->cmd[0], "unset"))
		unset(&pipe->data->envp, cmd->cmd);
	else if (!ft_strcmp(cmd->cmd[0], "env"))
		env(pipe->data->envp);
	else if (!ft_strcmp(cmd->cmd[0], "exit"))
		ms_exit(cmd->cmd, pipe->count);
	else
		return (0);
	return (1);
}

int	check_redir(t_pipe_cmd *cmd, t_pipe_redir *redir)
{
	if (redir->flag == I_REDIR)
		insert_input(cmd, redir->file);
	else if (redir->flag == D_I_REDIR)
		insert_input(cmd, cmd->hd_file);
	else if (redir->flag == O_REDIR)
	{
		cmd->ofd_append = 0;
		if (create_output_file(cmd, redir->file))
			return (1);
	}
	else if (redir->flag == D_O_REDIR)
	{
		cmd->ofd_append = 1;
		if (create_output_file(cmd, redir->file))
			return (1);
	}
	return (0);
}

void	set_child(t_pipe *pipe, int n)
{
	t_list	*temp;
	t_list	*temp_redir;
	int		m;

	temp = pipe->cmd;
	m = n;
	while (m--)
		temp = temp->next;
	temp_redir = ((t_pipe_cmd *)temp->content)->redir;
	while (temp_redir)
	{
		if (check_redir(temp->content, temp_redir->content))
			exit(1);
		check_access(temp->content);
		temp_redir = temp_redir->next;
	}
	set_fd(temp->content);
	set_pipe_fd(pipe, temp->content, n);
	pipe_redirect(temp->content);
	close_fd(pipe);
	if (!check_builtin(pipe, temp->content))
		pipe_let_cmd(pipe, temp->content);
	exit(g_errno);
}

void	pipe_create_child(t_pipe *pipe)
{
	int	n;

	n = 0;
	signal(SIGINT, signal_handler_sigint_p);
	signal(SIGQUIT, signal_handler_sigquit);
	pipe->pid = (pid_t *)malloc(sizeof(pid_t) * pipe->count);
	if (!pipe->pid)
		error_exit();
	while (n < pipe->count)
	{
		pipe->pid[n] = fork();
		if (pipe->pid[n] < 0)
			error_exit();
		else if (pipe->pid[n] == 0)
			set_child(pipe, n);
		n++;
	}
	close_fd(pipe);
}
