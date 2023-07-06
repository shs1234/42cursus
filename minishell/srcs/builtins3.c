/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gibkim <gibkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 08:13:49 by hoseoson          #+#    #+#             */
/*   Updated: 2023/07/03 20:00:47 by gibkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	valid_key(char *key)
{
	if (ft_isdigit(*key))
		return (0);
	while (ft_isalnum(*key) || *key == '_')
		key++;
	if (*key)
		return (0);
	return (1);
}

static int	valid_syntax(char *cmd, int *temp_errno)
{
	char	**key_val;

	if (cmd[0] == '=' || ft_isdigit(cmd[0]))
	{
		ft_putstr_fd("export: not a valid identifier\n", STDERR_FILENO);
		*temp_errno = 1;
		return (0);
	}
	key_val = ft_split(cmd, '=');
	if (!key_val)
		error_exit();
	if (!valid_key(key_val[0]))
	{
		ft_putstr_fd("export: not a valid identifier\n", STDERR_FILENO);
		free_lines(key_val);
		*temp_errno = 1;
		return (0);
	}
	if (!key_val[1])
	{
		free_lines(key_val);
		return (0);
	}
	return (1);
}

static void	unset_key(t_data *data, char *key_val)
{
	char	**cmd;
	char	*equal;

	cmd = ft_calloc(3, sizeof(char *));
	if (!cmd)
		error_exit();
	cmd[0] = ft_strdup("unset");
	cmd[1] = ft_strdup(key_val);
	if (!cmd[0] || !cmd[1])
		error_exit();
	equal = ft_strchr(cmd[1], '=');
	*equal = '\0';
	unset(&data->envp, cmd);
	free_lines(cmd);
}

void	export(t_data *data, char **cmd)
{
	char	*str;
	int		i;
	int		temp_errno;

	g_errno = 0;
	temp_errno = 0;
	if (!cmd[1])
		return (env(data->envp));
	i = 1;
	while (cmd[i])
	{
		if (valid_syntax(cmd[i], &temp_errno))
		{
			unset_key(data, cmd[i]);
			str = ft_strdup(cmd[i]);
			if (!str)
				error_exit();
			newaddback(&data->envp, str);
		}
		i++;
	}
	g_errno = temp_errno;
}

void	pwd(void)
{
	char	buf[PATH_MAX];

	if (!getcwd(buf, PATH_MAX))
		return (perror("getcwd"));
	ft_putendl_fd(buf, STDOUT_FILENO);
	g_errno = 0;
}
