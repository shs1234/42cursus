/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gibkim <gibkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:06:52 by hoseoson          #+#    #+#             */
/*   Updated: 2023/07/03 20:00:43 by gibkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	option_n(char *str)
{
	if (*str++ != '-')
		return (0);
	while (*str == 'n')
		str++;
	if (*str)
		return (0);
	return (1);
}

void	echo(char **tokens)
{
	int	op;

	op = 0;
	tokens++;
	while (*tokens && option_n(*tokens))
	{
		tokens++;
		op = 1;
	}
	while (*tokens)
	{
		ft_putstr_fd(*tokens, STDOUT_FILENO);
		tokens++;
		if (*tokens)
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	if (!op)
		ft_putchar_fd('\n', STDOUT_FILENO);
	g_errno = 0;
}

static int	cd_valid(char **cmd)
{
	if (!cmd[1])
		return (0);
	if (access(cmd[1], F_OK) == -1)
	{
		perror(cmd[1]);
		g_errno = 1;
		return (0);
	}
	return (1);
}

void	ch_oldpwd(t_data *data, char *val, char **key_val)
{
	key_val[1] = ft_strjoin("OLDPWD=", val);
	if (!key_val[1])
		error_exit();
	export(data, key_val);
	free(key_val[1]);
}

void	cd(t_data *data, char **cmd)
{
	char	**key_val;
	char	val[PATH_MAX];

	if (!cd_valid(cmd))
		return ;
	if (!getcwd(val, PATH_MAX))
		return (perror("getcwd"));
	key_val = ft_calloc(3, sizeof(char *));
	if (!key_val)
		error_exit();
	ch_oldpwd(data, val, key_val);
	chdir(cmd[1]);
	if (!getcwd(val, PATH_MAX))
	{
		free_lines(key_val);
		return (perror("getcwd"));
	}
	key_val[1] = ft_strjoin("PWD=", val);
	if (!key_val)
		error_exit();
	export(data, key_val);
	free_lines(key_val);
	g_errno = 0;
}
