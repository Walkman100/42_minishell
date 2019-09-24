/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:49:15 by mcarter           #+#    #+#             */
/*   Updated: 2019/09/24 14:24:53 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*input;
	t_userinput	userinput;
	char		**path;
	char		*program_path;

	path = get_path_from_envp(envp);
	while (1)
	{
		show_prompt(envp);
		input = get_input();
		userinput = parse_input(input);
		if (userinput.is_builtin)
		{
			run_function(userinput, envp);
		}
		else
		{
			program_path = get_path(path, userinput.program_name);
			wait_for_pid(run_program(program_path, userinput));
		}
	}
	return (0);
}
