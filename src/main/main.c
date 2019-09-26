/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:49:15 by mcarter           #+#    #+#             */
/*   Updated: 2019/09/26 19:27:29 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_envp(char ***envp)
{
	MAXUNBR			arrlen;
	char			**tmpenvp;
	char			cwd[1024];

	arrlen = ft_parrlen((void **)*envp);
	tmpenvp = ft_memalloc(sizeof(**envp) * (arrlen + 1));
	ft_memcpy(tmpenvp, *envp, sizeof(**envp) * arrlen);
	*envp = tmpenvp;
	set_envvar(envp, "SHELL=", "minishell");
	set_envvar(envp, "BASH=", "minishell");
	if (getcwd(cwd, 1023))
		set_envvar(envp, "PWD=", cwd);
}

int		main(int argc, char **argv, char **envp)
{
	char		*input;
	t_userinput	userinput;
	char		**path;
	char		*program_path;

	init_envp(&envp);
	path = get_path_from_envp(envp);
	while (1)
	{
		show_prompt(envp);
		if ((input = get_input()))
		{
			userinput = parse_input(input, envp);
			set_envvar(&envp, "_=", userinput.program_name);
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
			ft_putchar('\n');
			break ;
		}
	}
	return (0);
}
