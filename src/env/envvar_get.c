/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envvar_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:50:18 by mcarter           #+#    #+#             */
/*   Updated: 2019/10/01 15:55:14 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*envvar_get(char **envp, char *varname)
{
	int	varnamelen;

	varnamelen = ft_strlen(varname);
	while (*envp && !ft_strnequ(*envp, varname, varnamelen))
		envp++;
	if (!*envp)
		return (NULL);
	return ((*envp) + varnamelen);
}
