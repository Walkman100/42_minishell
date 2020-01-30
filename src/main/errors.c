/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:31:11 by mcarter           #+#    #+#             */
/*   Updated: 2020/01/30 11:56:13 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	put_error(int errno_l, char *msg, char *dbg, const char *caller_name)
{
	debug_2(dbg, caller_name);
	errno = errno_l;
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	perror(msg);
}

void	exit_msg(int errno_l, char *msg, char *dbg, const char *caller_name)
{
	put_error(errno_l, msg, dbg, caller_name);
	exit(EXIT_FAILURE);
}
