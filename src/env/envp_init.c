/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:50:43 by mcarter           #+#    #+#             */
/*   Updated: 2019/10/01 15:53:13 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	envp_init(char ***envp, char **argv)
{
	MAXUNBR		arrlen;
	char		**tmpenvp;
	char		cwd[1024];

	arrlen = ft_parrlen((void **)*envp);
	tmpenvp = ft_memalloc(sizeof(**envp) * (arrlen + 1));
	ft_memcpy(tmpenvp, *envp, sizeof(**envp) * arrlen);
	*envp = tmpenvp;
	while (*tmpenvp)
	{
		*tmpenvp = ft_strdup(*tmpenvp);
		tmpenvp++;
	}
	envvar_set(envp, "SHELL=", *argv);
	envvar_set(envp, "BASH=", *argv);
	if (getcwd(cwd, 1023))
		envvar_set(envp, "PWD=", cwd);
}
