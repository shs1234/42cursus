/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:07:12 by hoseoson          #+#    #+#             */
/*   Updated: 2023/07/01 11:34:19 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	del_env(t_list **lst, char *key, size_t len)
{
	t_list	*lst_copy;
	t_list	*lst_prev;

	lst_copy = *lst;
	lst_prev = *lst;
	while (lst_copy)
	{
		if (!ft_strncmp((char *)lst_copy->content, key, len)
			&& ((char *)lst_copy->content)[len] == '=')
		{
			if (lst_prev == lst_copy)
				*lst = (*lst)->next;
			else
				lst_prev->next = lst_copy->next;
			ft_lstdelone(lst_copy, free);
			break ;
		}
		lst_prev = lst_copy;
		lst_copy = lst_copy->next;
	}
}

void	unset(t_list **lst, char **key)
{
	size_t	len;

	while (*++key)
	{
		len = ft_strlen(*key);
		del_env(lst, *key, len);
	}
	g_errno = 0;
}

void	env(t_list *envp)
{
	while (envp)
	{
		ft_putendl_fd((char *)envp->content, STDOUT_FILENO);
		envp = envp->next;
	}
	g_errno = 0;
}

static int	valid_exit(char **cmd)
{
	int	i;

	i = 0;
	if (cmd[1][i] == '+' || cmd[1][i] == '-')
		i++;
	while (cmd[1][i])
	{
		if (!ft_isdigit(cmd[1][i]))
		{
			ft_putstr_fd("exit: numeric argument required\n", STDERR_FILENO);
			exit(255);
		}
		i++;
	}
	if (!ft_islong(cmd[1]))
	{
		ft_putstr_fd("exit: numeric argument required\n", STDERR_FILENO);
		exit(255);
	}
	return (1);
}

void	ms_exit(char **cmd, int cmd_count)
{
	char	exit_code;

	if (cmd_count == 1)
		ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (!cmd[1])
		exit(g_errno);
	if (cmd[2])
	{
		ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
		exit(1);
	}
	if (valid_exit(cmd))
	{
		exit_code = ft_atoi(cmd[1]);
		exit(exit_code);
	}
}
