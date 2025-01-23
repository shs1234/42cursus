/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:32:59 by gibkim            #+#    #+#             */
/*   Updated: 2023/06/30 03:58:23 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenizer_quote(t_data *data, t_split *s)
{
	t_token	*token;

	s->i++;
	while (s->i < s->len && data->line[s->start] != data->line[s->i])
		s->i++;
	token = malloc(sizeof(t_token));
	if (!token)
		error_exit();
	token->str = ft_substr(data->line, s->start + 1, s->i - s->start - 1);
	if (!token->str)
		error_exit();
	token->meta = STR;
	if (data->line[s->start] == '\"')
		expansion(data, token);
	if (s->prev_meta == STR)
		tokenjoin(data, token);
	else
		newaddback(&data->lst, token);
	s->i++;
	s->prev_meta = STR;
}

void	tokenizer_str(t_data *data, t_split *s)
{
	t_token	*token;

	while (s->i < s->len && !ft_iswhitespace(data->line[s->i])
		&& data->line[s->i] != '<' && data->line[s->i] != '>'
		&& !ft_isquote(data->line[s->i]) && data->line[s->i] != '|')
		s->i++;
	if (s->i > s->start)
	{
		token = malloc(sizeof(t_token));
		if (!token)
			error_exit();
		token->meta = STR;
		token->str = ft_substr(data->line, s->start, s->i - s->start);
		if (!token->str)
			error_exit();
		expansion(data, token);
		if (s->prev_meta == STR)
			tokenjoin(data, token);
		else
			newaddback(&data->lst, token);
	}
	s->prev_meta = STR;
}

void	tokenizer_pipe(t_data *data, t_split *s)
{
	t_token	*token;

	s->i++;
	token = malloc(sizeof(t_token));
	if (!token)
		error_exit();
	token->meta = PIPE;
	token->str = ft_strdup("|");
	if (!token->str)
		error_exit();
	newaddback(&data->lst, token);
	s->prev_meta = PIPE;
}

void	tokenizer_redirection(t_data *data, t_split *s)
{
	t_token	*token;

	if (!ft_strncmp(&data->line[s->start], "<<", 2)
		|| !ft_strncmp(&data->line[s->start], ">>", 2))
		s->i += 2;
	else if (data->line[s->start] == '<' || data->line[s->start] == '>')
		s->i++;
	if (s->i > s->start)
	{
		token = malloc(sizeof(t_token));
		if (!token)
			error_exit();
		token->meta = REDIR;
		token->str = ft_substr(data->line, s->start, s->i - s->start);
		if (!token->str)
			error_exit();
		newaddback(&data->lst, token);
	}
	s->prev_meta = REDIR;
}
