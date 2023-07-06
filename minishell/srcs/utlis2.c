/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 08:27:30 by hoseoson          #+#    #+#             */
/*   Updated: 2023/07/04 16:20:28 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error_exit(char *cmd, char *errmsg, int exit_code)
{
	char	*errcmd;
	char	*temp;
	char	*temp2;

	temp = ft_strjoin(cmd, ": ");
	if (!temp)
		error_exit();
	temp2 = ft_strjoin(temp, errmsg);
	if (!temp2)
		error_exit();
	errcmd = ft_strjoin(temp2, "\n");
	if (!errcmd)
		error_exit();
	if (temp)
		free(temp);
	if (temp2)
		free(temp2);
	ft_putstr_fd(errcmd, STDERR_FILENO);
	if (exit_code == -1)
	{
		if (errcmd)
			free(errcmd);
		return ;
	}
	exit(exit_code);
}

static int	ft_numlen(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_longornot(const char *str, long long cutoff, long long cutlim)
{
	long long	num;
	int			len;
	int			longlen;

	num = 0;
	len = 0;
	longlen = ft_numlen(LONG_MAX);
	while (ft_isdigit(*str))
	{
		num = (10 * num) + (*str - '0');
		len++;
		if (ft_isdigit(*(str + 1)) && (num > cutlim || (num == cutlim && *(str
						+ 1) - '0' > cutoff) || (len == longlen - 1
					&& num < cutlim && ft_isdigit(*(str + 2)))))
			return (0);
		str++;
	}
	return (1);
}

int	ft_islong(const char *str)
{
	long long	cutlim;
	long long	cutoff;

	cutlim = LONG_MAX / 10;
	cutoff = LONG_MAX % 10;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			cutoff++;
		str++;
	}
	while (*str == '0')
		str++;
	return (ft_longornot(str, cutoff, cutlim));
}

int	isredirection(int i)
{
	if (i == PIPE || i == REDIR)
		return (1);
	return (0);
}
