/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:03:31 by mcarter           #+#    #+#             */
/*   Updated: 2019/09/26 16:55:04 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_cd(char *args, char **envp)
{
	char	cwd[1024];

	if (chdir(args))
		perror(args);
	else if (getcwd(cwd, 1023))
		set_envvar(envp, "PWD=", cwd);
}
