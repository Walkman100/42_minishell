/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:04:34 by mcarter           #+#    #+#             */
/*   Updated: 2019/10/01 12:25:22 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_env(char *args, char ***envp)
{
	char	**tmpenvp;

	tmpenvp = *envp;
	if (args)
	{
		// do stuff
	}
	else
	{
		while (*tmpenvp)
		{
			ft_putendl(*tmpenvp);
			tmpenvp++;
		}
	}
}
