/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:04:20 by mcarter           #+#    #+#             */
/*   Updated: 2019/10/01 15:45:32 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_unsetenv(char *args, char ***envp)
{
	MAXUNBR	varnamelen;
	char	**oldenvp;
	char	**tmpoldenvp;
	char	**tmpnewenvp;
	char	*varname;

	if (args)
	{
		varnamelen = ft_strlen(args);
		varname = ft_strsub(args, 0, varnamelen + 1);
		varname[varnamelen] = '=';
		if (get_envvar(*envp, varname))
		{
			oldenvp = *envp;
			tmpoldenvp = oldenvp;
			*envp = ft_memalloc(sizeof(**envp) * ft_parrlen((void **)oldenvp));
			tmpnewenvp = *envp;
			while (*tmpoldenvp)
			{
				*tmpnewenvp = *tmpoldenvp;
				tmpnewenvp++;
				tmpoldenvp++;
				if (ft_strnequ(*tmpoldenvp, varname, varnamelen + 1))
					tmpoldenvp++;
			}
		}
		else
			ft_printf("minishell: unsetenv: variable '%s' does not exist\n", \
																		args);
	}
	else
		ft_putendl("unsetenv usage: unsetenv <envvar>");
}
