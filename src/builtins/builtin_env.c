/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:04:34 by mcarter           #+#    #+#             */
/*   Updated: 2019/10/02 14:09:14 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_env(char *args, char ***envp)
{
	char		**tmpenvp;
	char		**path;
	char		*program_path;
	t_userinput	userinput;

	tmpenvp = *envp;
	if (args)
	{
		if (ft_strchr(args, '='))
			builtin_setenv(args, envp);
		else
		{
			userinput = parse_input(args, envp);
			if (userinput.program_name && userinput.program_name[0])
			{
				path = get_path_from_envp(*envp);
				if ((program_path = get_path(path, userinput.program_name)))
					wait_for_pid(run_program(program_path, userinput, *envp));
			}
		}
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
