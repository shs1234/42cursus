/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_create_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:21:58 by gibkim            #+#    #+#             */
/*   Updated: 2023/07/04 16:25:47 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	chk_output_file(char *file)
{
	char	*temp;

	if (!ft_strchr(file, '/'))
		return (0);
	temp = ft_substr(file, 0, ft_strlen(file) - ft_strlen(ft_strrchr(file,
					'/')));
	if (temp && access(temp, F_OK) < 0)
	{
		free(temp);
		print_error_exit(file, "No such file or directory", -1);
		return (1);
	}
	if (temp)
		free(temp);
	return (0);
}

int	create_output_file(t_pipe_cmd *cmd, char *file)
{
	int	fd;

	if (chk_output_file(file))
		return (1);
	fd = open(file, O_CREAT, 0644);
	if (fd < 0)
		error_exit();
	if (close(fd) < 0)
		error_exit();
	insert_output(cmd, file);
	return (0);
}
