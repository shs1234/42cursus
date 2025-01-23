/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:01:43 by gibkim            #+#    #+#             */
/*   Updated: 2023/07/04 16:25:23 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clean_pipe_cmd(void *content)
{
	t_pipe_cmd	*temp;

	temp = content;
	free_lines(temp->cmd);
	ft_lstclear(&temp->redir, free_token);
	if (temp->input)
		free(temp->input);
	if (temp->output)
		free(temp->output);
	if (temp->hd_file)
		free(temp->hd_file);
	free(temp);
}

void	free_pipe(t_pipe *pipe)
{
	int	n;

	n = 0;
	ft_lstclear(&pipe->cmd, clean_pipe_cmd);
	while (n < pipe->count - 1)
	{
		if (pipe->fd[n])
			free(pipe->fd[n]);
		n++;
	}
	if (pipe->fd)
		free(pipe->fd);
	if (pipe->path)
		free_lines(pipe->path);
	if (pipe->pid)
		free(pipe->pid);
}

void	insert_input(t_pipe_cmd *cmd, char *input)
{
	if (cmd->input)
		free(cmd->input);
	cmd->input = ft_strdup(input);
	if (!cmd->input)
		error_exit();
}

void	insert_output(t_pipe_cmd *cmd, char *output)
{
	if (cmd->output)
		free(cmd->output);
	cmd->output = ft_strdup(output);
	if (!cmd->output)
		error_exit();
}
