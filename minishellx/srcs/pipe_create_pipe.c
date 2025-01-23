/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_create_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:15:14 by gibkim            #+#    #+#             */
/*   Updated: 2023/06/28 07:57:49 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_pipe(int **fd, int n)
{
	int	*temp;

	temp = (int *)malloc(sizeof(int) * 2);
	if (!temp)
		error_exit();
	if (pipe(temp) < 0)
		error_exit();
	fd[n] = temp;
}

void	create_pipe(t_pipe *pipe)
{
	t_pipe_cmd	*temp;
	int			**fd;
	int			n;

	temp = pipe->cmd->content;
	if (pipe->count == 1)
	{
		pipe->fd = NULL;
		return ;
	}
	fd = (int **)malloc(sizeof(int *) * (pipe->count - 1));
	if (!fd)
		error_exit();
	n = 0;
	while (n < pipe->count - 1)
	{
		if (!temp->output)
			add_pipe(fd, n);
		else
			fd[n] = NULL;
		n++;
	}
	pipe->fd = fd;
}
