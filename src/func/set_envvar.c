/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envvar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:00:01 by mcarter           #+#    #+#             */
/*   Updated: 2019/09/26 19:34:47 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_envvar(char ***envp, char *varname, char *varvalue)
{
	int		varnamelen;
	char	**tmpenvp;
	char	*newvar;

	varnamelen = ft_strlen(varname);
	newvar = ft_strnew(varnamelen + ft_strlen(varvalue));
	ft_strcpy(newvar, varname);
	ft_strcat(newvar, varvalue);
	tmpenvp = *envp;
	while (*tmpenvp && !ft_strnequ(*tmpenvp, varname, varnamelen))
		tmpenvp++;
	if (*tmpenvp)
	{
		//ft_strdel(tmpenvp);
		*tmpenvp = newvar;
	}
	else
	{
		*envp = ft_realloc(*envp,
							sizeof(**envp) * (ft_parrlen((void **)*envp) + 2));
		tmpenvp = *envp;
		while (*tmpenvp)
			tmpenvp++;
		*tmpenvp = newvar;
		*(tmpenvp + 1) = NULL;
	}
}
