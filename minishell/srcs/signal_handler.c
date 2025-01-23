/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:45:10 by gibkim            #+#    #+#             */
/*   Updated: 2023/07/04 15:08:38 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler_sigquit(int sig)
{
	(void)sig;
	kill(0, SIGQUIT);
	ft_putstr_fd("Quit: 3\n", STDERR_FILENO);
	signal(SIGQUIT, SIG_IGN);
}

void	signal_handler_sigint_p(int sig)
{
	(void)sig;
	kill(0, SIGINT);
	printf("\n");
	signal(SIGINT, SIG_IGN);
}

void	signal_handler_sigint(int sig)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_errno = sig + 128;
}
