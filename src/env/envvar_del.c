/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envvar_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:50:34 by mcarter           #+#    #+#             */
/*   Updated: 2019/10/01 16:50:09 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	envvar_del(char ***envp, char *varname)
{
	MAXUNBR	varnamelen;
	char	**oldenvp;
	char	**tmpoldenvp;
	char	**tmpnewenvp;

	ft_putendl("started");
	ft_putendl(varname);
	varnamelen = ft_strlen(varname);
	oldenvp = *envp;
	tmpoldenvp = oldenvp;
	*envp = ft_memalloc(sizeof(**envp) * ft_parrlen((void **)oldenvp));
	tmpnewenvp = *envp;
	while (*tmpoldenvp)
	{
		*tmpnewenvp = *tmpoldenvp;
		tmpnewenvp++;
		tmpoldenvp++;
		if (ft_strnequ(*tmpoldenvp, varname, varnamelen))
		{
			ft_strdel(tmpoldenvp);
			tmpoldenvp++;
		}
	}
	MEMDEL(oldenvp);
}
