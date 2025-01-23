/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_split_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:36:03 by gibkim            #+#    #+#             */
/*   Updated: 2023/07/04 15:07:40 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pipe_add_redir(t_pipe_cmd *cmd, t_list *lst)
{
	t_pipe_redir	*redir;

	redir = (t_pipe_redir *)ft_calloc(1, sizeof(t_pipe_redir));
	if (!redir)
		error_exit();
	redir->file = ft_strdup(((t_token *)lst->next->content)->str);
	if (!redir->file)
		error_exit();
	if (!ft_strcmp(((t_token *)lst->content)->str, "<"))
		redir->flag = I_REDIR;
	else if (!ft_strcmp(((t_token *)lst->content)->str, "<<"))
	{
		read_heredoc(cmd, redir->file);
		redir->flag = D_I_REDIR;
	}
	else if (!ft_strcmp(((t_token *)lst->content)->str, ">"))
		redir->flag = O_REDIR;
	else if (!ft_strcmp(((t_token *)lst->content)->str, ">>"))
		redir->flag = D_O_REDIR;
	newaddback(&cmd->redir, redir);
}

static void	convert_cmd_listtoarray(t_list *list, t_pipe_cmd *cmd)
{
	t_list	*temp;
	int		n;
	int		lstsize;

	temp = list;
	lstsize = ft_lstsize(list);
	n = 0;
	cmd->cmd = (char **)malloc(sizeof(char *) * (lstsize + 1));
	if (!cmd->cmd)
		error_exit();
	cmd->cmd[lstsize] = NULL;
	while (n < lstsize)
	{
		cmd->cmd[n] = ft_strdup((char *)temp->content);
		if (!cmd->cmd[n])
			error_exit();
		n++;
		temp = temp->next;
	}
}

static void	lstaddback_malloc(t_list **cmd_lst, t_list *lst)
{
	char	*str;
	t_list	*temp;

	str = ft_strdup(((t_token *)lst->content)->str);
	if (!str)
		error_exit();
	temp = ft_lstnew((void *)str);
	if (!temp)
		error_exit();
	ft_lstadd_back(cmd_lst, temp);
}

static int	pipe_add_cmd(t_pipe *pipe, t_list *lst)
{
	t_pipe_cmd	*cmd;
	t_list		*cmd_lst;

	cmd_lst = NULL;
	cmd = (t_pipe_cmd *)ft_calloc(1, sizeof(t_pipe_cmd));
	if (!cmd)
		error_exit();
	while (lst && ((t_token *)lst->content)->meta != PIPE)
	{
		if (isredirection(((t_token *)lst->content)->meta))
		{
			pipe_add_redir(cmd, lst);
			lst = lst->next;
		}
		else
			lstaddback_malloc(&cmd_lst, lst);
		lst = lst->next;
	}
	convert_cmd_listtoarray(cmd_lst, cmd);
	ft_lstclear(&cmd_lst, free);
	newaddback(&pipe->cmd, cmd);
	return (0);
}

int	pipe_split_cmd(t_pipe *pipe)
{
	t_list	*lst;

	pipe->count = 0;
	pipe->cmd = NULL;
	lst = pipe->data->lst;
	while (lst && ((t_token *)lst->content)->meta != PIPE)
	{
		if (pipe_add_cmd(pipe, lst))
			return (1);
		while (lst && ((t_token *)lst->content)->meta != PIPE)
			lst = lst->next;
		if (lst)
			lst = lst->next;
		pipe->count++;
	}
	return (0);
}
