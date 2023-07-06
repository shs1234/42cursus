/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:29:42 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/28 09:02:38 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	tokenizer_dollar(t_list **lst, t_split *s, char *str)
{
	char	*sub;

	s->start = s->i;
	s->i++;
	if (str[s->start] == '$')
	{
		if (str[s->i] == '?')
			s->i++;
		else
		{
			if (!ft_isdigit(str[s->i]))
			{
				while (s->i < s->len && (ft_isalnum(str[s->i])
						|| str[s->i] == '_'))
					s->i++;
			}
		}
	}
	else
		while (s->i < s->len && str[s->i] != '$')
			s->i++;
	sub = ft_substr(str, s->start, s->i - s->start);
	if (!sub)
		error_exit();
	newaddback(lst, sub);
}

static char	*get_exitstatus(void)
{
	char	*val;

	val = ft_itoa(g_errno);
	if (!val)
		error_exit();
	return (val);
}

static void	sub_dollar(t_data *data, t_list *lst)
{
	char	*val;

	while (lst)
	{
		if (((char *)lst->content)[0] == '$' && ((char *)lst->content)[1])
		{
			if (!ft_strcmp(&((char *)lst->content)[1], "?"))
				val = get_exitstatus();
			else
			{
				val = get_val(data, &((char *)lst->content)[1]);
				if (val)
				{
					val = ft_strdup(val);
					if (!val)
						error_exit();
				}
			}
			free(lst->content);
			lst->content = val;
		}
		lst = lst->next;
	}
}

static char	*lstcat(t_list *lst)
{
	char	*str;
	size_t	len;
	t_list	*list;

	list = lst;
	len = 0;
	while (list)
	{
		if (list->content)
			len += ft_strlen(list->content);
		list = list->next;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		error_exit();
	*str = '\0';
	while (lst)
	{
		if (lst->content)
			ft_strlcat(str, lst->content, len + 1);
		lst = lst->next;
	}
	return (str);
}

void	expansion(t_data *data, t_token *token)
{
	t_split	s;
	t_list	*lst;
	char	*expanded;
	char	*str;

	str = token->str;
	if (!ft_strchr(str, '$'))
		return ;
	lst = NULL;
	s.i = 0;
	s.len = ft_strlen(str);
	while (s.i < s.len)
		tokenizer_dollar(&lst, &s, str);
	sub_dollar(data, lst);
	expanded = lstcat(lst);
	free(str);
	ft_lstclear(&lst, free);
	token->str = expanded;
}
