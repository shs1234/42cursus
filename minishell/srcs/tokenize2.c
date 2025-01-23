/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gibkim <gibkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:53:57 by hoseoson          #+#    #+#             */
/*   Updated: 2023/07/03 19:34:24 by gibkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	tokenizer(t_data *data, t_split *s)
{
	if (s->i < s->len && ft_isquote(data->line[s->i]))
		tokenizer_quote(data, s);
	else if (s->i < s->len && data->line[s->i] == '|')
		tokenizer_pipe(data, s);
	else if (s->i < s->len && (data->line[s->i] == '<'
			|| data->line[s->i] == '>'))
		tokenizer_redirection(data, s);
	else
		tokenizer_str(data, s);
	s->token_count++;
}

int	tokenize(t_data *data)
{
	t_split	s;

	s.i = 0;
	s.prev_meta = -1;
	s.token_count = 0;
	s.len = ft_strlen(data->line);
	while (s.i < s.len)
	{
		while (s.i < s.len && ft_iswhitespace(data->line[s.i]))
		{
			s.i++;
			s.prev_meta = -1;
		}
		s.start = s.i;
		tokenizer(data, &s);
		if (s.i - s.start > TMAXLEN || s.token_count > TMAXCOUNT)
			return (invalid_input(data));
	}
	return (1);
}
