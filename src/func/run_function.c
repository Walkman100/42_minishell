/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:45:35 by mcarter           #+#    #+#             */
/*   Updated: 2019/10/01 12:17:21 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_function(t_userinput userinput, char ***envp)
{
	if (ft_strequ(userinput.program_name, "echo"))
		builtin_echo(userinput.program_args);
	else if (ft_strequ(userinput.program_name, "exit"))
		builtin_exit(userinput.program_args);
	else if (ft_strequ(userinput.program_name, "clear"))
		builtin_clear();
	else if (ft_strequ(userinput.program_name, "cd"))
		builtin_cd(userinput.program_args, envp);
	else if (ft_strequ(userinput.program_name, ".."))
		builtin_cd("..", envp);
	else if (ft_strequ(userinput.program_name, "pwd"))
		builtin_pwd(userinput.program_args);
	else if (ft_strequ(userinput.program_name, "setenv"))
		builtin_setenv(userinput.program_args, envp);
	else if (ft_strequ(userinput.program_name, "unsetenv"))
		builtin_unsetenv(userinput.program_args, envp);
	else if (ft_strequ(userinput.program_name, "env"))
		builtin_env(userinput.program_args, envp);
}
