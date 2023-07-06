/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:33:41 by hoseoson          #+#    #+#             */
/*   Updated: 2023/06/28 11:33:49 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_val(t_data *data, char *key)
{
	t_list	*envp;
	size_t	key_len;

	envp = data->envp;
	key_len = ft_strlen(key);
	while (envp)
	{
		if (!ft_strncmp(envp->content, key, key_len)
			&& ((char *)envp->content)[key_len] == '=')
			return (&((char *)envp->content)[key_len + 1]);
		envp = envp->next;
	}
	return (NULL);
}

void	tokenjoin(t_data *data, t_token *token)
{
	t_list	*last;
	char	*s1;
	char	*s2;
	char	*join;

	last = ft_lstlast(data->lst);
	s1 = ((t_token *)last->content)->str;
	s2 = token->str;
	join = ft_strjoin(s1, s2);
	if (!join)
		error_exit();
	((t_token *)last->content)->str = join;
	free(s1);
	free(s2);
}

void	newaddback(t_list **lst, void *content)
{
	t_list	*node;

	node = ft_lstnew(content);
	if (!node)
		error_exit();
	ft_lstadd_back(lst, node);
}
