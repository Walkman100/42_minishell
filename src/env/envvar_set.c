/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envvar_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:50:24 by mcarter           #+#    #+#             */
/*   Updated: 2019/10/01 16:04:50 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	envvar_add(char ***envp, char *newvar)
{
	char	**tmpenvp;

	*envp = ft_realloc(*envp, sizeof(**envp) * \
											(ft_parrlen((void **)*envp) + 2));
	tmpenvp = *envp;
	while (*tmpenvp)
		tmpenvp++;
	*tmpenvp = newvar;
	*(tmpenvp + 1) = NULL;
}

void	envvar_set(char ***envp, char *varname, char *varvalue)
{
	MAXUNBR	varnamelen;
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
		ft_strdel(tmpenvp);
		*tmpenvp = newvar;
	}
	else
		envvar_add(envp, newvar);
}
