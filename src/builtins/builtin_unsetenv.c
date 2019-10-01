/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:04:20 by mcarter           #+#    #+#             */
/*   Updated: 2019/10/01 16:34:27 by mcarter          ###   ########.fr       */
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
		if (envvar_get(*envp, varname))
			envvar_del(envp, varname);
		else
			ft_printf("minishell: unsetenv: variable '%s' does not exist\n", \
																		args);
	}
	else
		ft_putendl("unsetenv usage: unsetenv <envvar>");
}
