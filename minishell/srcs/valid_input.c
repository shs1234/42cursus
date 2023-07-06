/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 03:11:49 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/30 04:46:42 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	invalid_input(t_data *data)
{
	ft_putstr_fd("Error: invalid input\n", STDERR_FILENO);
	clean_data(data);
	return (0);
}

int	is_closed(t_data *data)
{
	char	*line_copy;
	int		single_q;
	int		double_q;

	line_copy = data->line;
	single_q = 0;
	double_q = 0;
	while (*line_copy)
	{
		if (*line_copy == '\'' && !double_q)
			single_q ^= 1;
		else if (*line_copy == '\"' && !single_q)
			double_q ^= 1;
		line_copy++;
	}
	if (single_q || double_q)
		return (invalid_input(data));
	return (1);
}

static int	valid_meta(int prev_meta, int cur_meta)
{
	if ((prev_meta == REDIR && cur_meta == PIPE) || (prev_meta == REDIR
			&& cur_meta == REDIR) || (prev_meta == PIPE && cur_meta == PIPE))
		return (0);
	return (1);
}

int	valid_tokens(t_data *data)
{
	t_list	*lst;
	t_list	*prev;
	int		prev_meta;
	int		cur_meta;

	lst = data->lst;
	if (!lst)
		return (1);
	if (!ft_strcmp(((t_token *)lst->content)->str, "|"))
		return (invalid_input(data));
	prev = lst;
	cur_meta = ((t_token *)lst->content)->meta;
	lst = lst->next;
	while (lst)
	{
		prev_meta = ((t_token *)prev->content)->meta;
		cur_meta = ((t_token *)lst->content)->meta;
		if (!valid_meta(prev_meta, cur_meta))
			return (invalid_input(data));
		prev = lst;
		lst = lst->next;
	}
	if (cur_meta == REDIR || cur_meta == PIPE)
		return (invalid_input(data));
	return (1);
}

int	in_argmax(t_data *data)
{
	int	i;

	i = 0;
	while (data->line[i])
	{
		i++;
		if (i > ARGMAX)
			return (invalid_input(data));
	}
	return (1);
}
