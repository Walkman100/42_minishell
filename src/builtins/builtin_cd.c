/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:03:31 by mcarter           #+#    #+#             */
/*   Updated: 2019/10/21 15:00:18 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_cd(char *args, char ***envp)
{
	char	cwd[1024];
	char	*gcwdrtn;

	gcwdrtn = getcwd(cwd, 1023);
	while (args && *args == ' ')
		args++;
	if (!args || !*args)
		args = envvar_get(*envp, "HOME=");
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
