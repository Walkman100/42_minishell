/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:04:34 by mcarter           #+#    #+#             */
/*   Updated: 2019/09/26 16:58:32 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_env(char *args, char **envp)
{
	if (args)
	{
		// do stuff
	}
	else
	{
		while (*envp)
		{
			ft_putendl(*envp);
			envp++;
		}
	}
}
