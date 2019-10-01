/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:04:03 by mcarter           #+#    #+#             */
/*   Updated: 2019/10/01 14:46:26 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_setenv(char *args, char ***envp)
{
	MAXUNBR	splitpos;
	char	*varname;

	if (args && ft_strchr(args, '='))
	{
		splitpos = ft_strclen(args, '=') + 1;
		varname = ft_strsub(args, 0, splitpos);
		args += splitpos;
		set_envvar(envp, varname, args);
		ft_strdel(&varname);
	}
	else if (args && ft_strchr(args, ' '))
	{
		splitpos = ft_strclen(args, ' ') + 1;
		varname = ft_strsub(args, 0, splitpos);
		varname[splitpos - 1] = '=';
		args += splitpos;
		set_envvar(envp, varname, args);
		ft_strdel(&varname);
	}
	else
		ft_putendl("setenv usage:\n" \
							"setenv <var> <value>\n OR \nsetenv <var>=<value>");
}
