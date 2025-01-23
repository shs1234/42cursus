/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 03:20:39 by hoseoson          #+#    #+#             */
/*   Updated: 2023/07/07 05:02:39 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned char	g_errno;

static int	data_init(char **envp, t_data *data)
{
	int		i;
	char	*str;
	t_list	*node;

	ft_bzero((void *)data, sizeof(t_data));
	i = 0;
	while (envp[i])
	{
		str = ft_strdup(envp[i]);
		if (!str)
			error_exit();
		node = ft_lstnew(str);
		if (!node)
			error_exit();
		ft_lstadd_back(&data->envp, node);
		i++;
	}
	return (0);
}

int	ms_putchar(int c)
{
	write(STDOUT_FILENO, &c, 1);
	return (0);
}

void	print_exit(void)
{
	char	*term;
	char	*buf;
	char	*del;
	char	*up;

	buf = NULL;
	term = getenv("TERM");
	if (tgetent(buf, term) <= 0)
	{
		ft_putstr_fd("Error: tgetent\n", STDERR_FILENO);
		exit(1);
	}
	up = tgetstr("up", &buf);
	del = tgetstr("dl", &buf);
	if (!up || !del)
	{
		ft_putstr_fd("Error: tgetstr\n", STDERR_FILENO);
		exit(1);
	}
	tputs(up, 1, ms_putchar);
	tputs(del, 1, ms_putchar);
	ft_putstr_fd("minishell$ exit\n", STDOUT_FILENO);
	exit(g_errno);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac != 1)
		return (1);
	(void)av;
	data_init(envp, &data);
	rl_catch_signals = 0;
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, signal_handler_sigint);
		data.line = readline(MINISHELL);
		if (!data.line)
			print_exit();
		if (*data.line)
			add_history(data.line);
		if (!in_argmax(&data) || !is_closed(&data) || !tokenize(&data)
			|| !valid_tokens(&data))
			continue ;
		pipe_line(&data);
		clean_data(&data);
	}
	ft_lstclear(&data.envp, free);
	return (0);
}
