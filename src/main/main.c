/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:49:15 by mcarter           #+#    #+#             */
/*   Updated: 2019/09/26 22:22:53 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_envp(char ***envp, char **argv)
{
	MAXUNBR			arrlen;
	char			**tmpenvp;
	char			cwd[1024];

	arrlen = ft_parrlen((void **)*envp);
	tmpenvp = ft_memalloc(sizeof(**envp) * (arrlen + 1));
	ft_memcpy(tmpenvp, *envp, sizeof(**envp) * arrlen);
	*envp = tmpenvp;
	set_envvar(envp, "SHELL=", *argv);
	set_envvar(envp, "BASH=", *argv);
	set_envvar(envp, "_=", "");
	if (getcwd(cwd, 1023))
	{
		set_envvar(envp, "OLDPWD=", "");
		set_envvar(envp, "PWD=", cwd);
	}
}

int		main(int argc, char **argv, char **envp)
{
	char		*input;
	t_userinput	userinput;
	char		**path;
	char		*program_path;

	init_envp(&envp, argv);
	path = get_path_from_envp(envp);
	while (1)
	{
		show_prompt(envp);
		if ((input = get_input()))
		{
			userinput = parse_input(input, envp);
			if (userinput.is_builtin)
			{
				run_function(userinput, envp);
			}
			else
			{
				if ((program_path = get_path(path, userinput.program_name)))
					wait_for_pid(run_program(program_path, userinput));
			}
			ft_strdel(&input);
		}
		else
		{
			ft_putstr("exit\n");
			break ;
		}
	}
	return (0);
}
