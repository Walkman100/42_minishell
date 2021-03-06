/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:02:01 by mcarter           #+#    #+#             */
/*   Updated: 2019/10/01 12:44:16 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_exit(char *args, char ***envp)
{
	free_envp(envp);
	if (args)
		exit(ft_atoi(args));
	else
		exit(EXIT_SUCCESS);
}
