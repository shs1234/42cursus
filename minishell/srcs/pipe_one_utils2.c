/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_one_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:42:59 by gibkim            #+#    #+#             */
/*   Updated: 2023/06/28 08:25:02 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fd_one(t_pipe_cmd *cmd)
{
	if (cmd->input && close(cmd->ifd) < 0)
		error_exit();
	if (cmd->output && close(cmd->ofd) < 0)
		error_exit();
}

void	restore_fd(int *fd)
{
	if (dup2(fd[0], STDIN_FILENO) < 0)
		error_exit();
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		error_exit();
	if (close(fd[0]) < 0)
		error_exit();
	if (close(fd[1]) < 0)
		error_exit();
}

void	one_pipe_dup(int *fd)
{
	fd[0] = dup(STDIN_FILENO);
	if (fd[0] < 0)
		error_exit();
	fd[1] = dup(STDOUT_FILENO);
	if (fd[1] < 0)
		error_exit();
}
