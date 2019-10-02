/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_pid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:45:29 by mcarter           #+#    #+#             */
/*   Updated: 2019/10/02 13:17:08 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	wait_for_pid(pid_t pid)
{
	int		stat_loc;

	if (pid == 0)
		return ;
	if (waitpid(pid, &stat_loc, 0) == -1)
		perror("minishell: waitpid: ");
}
