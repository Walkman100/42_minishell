/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:03:31 by mcarter           #+#    #+#             */
/*   Updated: 2019/10/01 16:32:17 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_cd(char *args, char ***envp)
{
	char	cwd[1024];
	char	*gcwdrtn;

	gcwdrtn = getcwd(cwd, 1024);
	if (chdir(args))
	{
		ft_putstr("minishell: cd: ");
		perror(args);
	}
	else
	{
		if (gcwdrtn)
			envvar_set(envp, "OLDPWD=", cwd);
		if (getcwd(cwd, 1023))
			envvar_set(envp, "PWD=", cwd);
	}
}
