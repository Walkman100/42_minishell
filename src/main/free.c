/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:38:11 by mcarter           #+#    #+#             */
/*   Updated: 2019/10/01 12:44:02 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_envp(char ***envp)
{
	char **tmpenvp;

	tmpenvp = *envp;
	while (*tmpenvp)
	{
		ft_strdel(tmpenvp);
		tmpenvp++;
	}
	ft_memdel((void **)envp);
}
