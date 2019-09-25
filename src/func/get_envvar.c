/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envvar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:55:34 by mcarter           #+#    #+#             */
/*   Updated: 2019/09/25 12:04:39 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_envvar(char **envp, char *varname)
{
	int	varnamelen;

	varnamelen = ft_strlen(varname);
	while (*envp && !ft_strnequ(*envp, varname, varnamelen))
		envp++;
	if (!*envp)
		return (NULL);
	return ((*envp) + varnamelen);
}
