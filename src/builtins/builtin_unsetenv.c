/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:04:20 by mcarter           #+#    #+#             */
/*   Updated: 2019/10/01 14:38:28 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_unsetenv(char *args, char ***envp)
{
	MAXUNBR	varnamelen;
	char	*varname;

	if (args)
	{
		varnamelen = ft_strlen(args);
		varname = ft_strsub(args, 0, varnamelen + 1);
		varname[varnamelen] = '=';
		if (get_envvar(*envp, varname))
		{
			set_envvar(envp, varname, "");
			ft_strdel(&varname);
		}
		else
		{
			ft_putstr("minishell: unsetenv: variable '");
			ft_putstr(args);
			ft_putendl("' does not exist");
		}
	}
	else
		ft_putendl("unsetenv usage: unsetenv <envvar>");
}
