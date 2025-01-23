/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:21:10 by gibkim            #+#    #+#             */
/*   Updated: 2023/07/04 16:25:36 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_pipe_path(t_pipe *pipe)
{
	char	**path;
	char	*temp;

	temp = get_val(pipe->data, "PATH");
	if (!temp)
		path = NULL;
	else
	{
		path = ft_split(temp, ':');
		if (!path)
			error_exit();
	}
	pipe->path = path;
}

void	set_pipe_exit(int statloc)
{
	g_errno = WEXITSTATUS(statloc) + (WIFSIGNALED(statloc) * (WTERMSIG(statloc)
				+ 128));
}

int	pipe_line(t_data *data)
{
	t_pipe	pipe;
	int		statloc;
	int		i;

	if (!data->lst)
		return (0);
	ft_bzero(&pipe, sizeof(t_pipe));
	pipe.data = data;
	set_pipe_path(&pipe);
	if (pipe_split_cmd(&pipe))
		return (1);
	if (pipe.count == 1)
		return (one_pipe(&pipe));
	create_pipe(&pipe);
	pipe_create_child(&pipe);
	i = -1;
	while (++i < pipe.count)
		if (waitpid(pipe.pid[i], &statloc, WUNTRACED) == -1)
			error_exit();
	set_pipe_exit(statloc);
	free_pipe(&pipe);
	return (0);
}
