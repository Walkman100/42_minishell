/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:49:15 by mcarter           #+#    #+#             */
/*   Updated: 2020/01/30 14:54:49 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_input(char *input, char **path, char ***envp)
{
	t_userinput	userinput;
	char		*program_path;

	userinput = parse_input(input, envp);
	if (userinput.is_builtin)
		run_function(userinput, envp);
	else if (userinput.program_name && userinput.program_name[0])
		if ((program_path = get_path(path, userinput.program_name)))
			wait_for_pid(run_program(program_path, userinput, *envp));
	ft_strdel(&input);
	ft_strdel(&(userinput.program_name));
	ft_strdel(&(userinput.program_args));
}

int		main(int argc, char **argv, char **envp)
{
	char	*input;
	char	**path;

	argc++;
	envp_init(&envp, argv);
	path = get_path_from_envp(envp);
	while (1)
	{
		show_prompt(envp);
		if ((input = get_input()))
		{
			run_input(input, path, &envp);
		}
		else
		{
			ft_putstr("exit\n");
			builtin_exit(NULL, &envp);
		}
	}
}
