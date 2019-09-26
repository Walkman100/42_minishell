/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envvar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:00:01 by mcarter           #+#    #+#             */
/*   Updated: 2019/09/26 16:23:32 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_envvar(char **envp, char *varname, char *varvalue)
{
	int		varnamelen;
	char	*newvar;

	varnamelen = ft_strlen(varname);
	while (*envp && !ft_strnequ(*envp, varname, varnamelen))
		envp++;
	newvar = ft_strnew(varnamelen + ft_strlen(varvalue));
	ft_strcpy(newvar, varname);
	ft_strcat(newvar, varvalue);
	if (*envp)
	{
		//ft_strdel(envp);
		*envp = newvar;
	}
	else
	{
		*envp = newvar;
		*(envp + 1) = NULL;
	}
}
