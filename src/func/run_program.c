/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:45:32 by mcarter           #+#    #+#             */
/*   Updated: 2019/10/02 11:15:01 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

pid_t	run_program(char *program_path, t_userinput userinput, char **envp)
{
	pid_t	rtn;
	char	**argv;
	MAXUNBR	avcount;

	if (userinput.program_args)
	{
		avcount = ft_chrcount(userinput.program_args, ' ') + 1;
		if (!(argv = ft_strsplit(userinput.program_args, ' ')))
		{
			ft_putendl("Out of memory!");
			exit(EXIT_FAILURE);
		}
		argv = ft_realloc(argv, sizeof(*argv) * (avcount + 2));
		ft_memmove(argv + 1, argv, sizeof(*argv) * (avcount + 1));
	}
	else
		argv = ft_memalloc(sizeof(*argv) * 2);
	argv[0] = userinput.program_name;
	if ((rtn = fork()) == 0)
	{
		if (execve(program_path, argv, envp))
		{
			ft_putstr("minishell: ");
			perror(program_path);
		}
		exit(EXIT_FAILURE);
	}
	else
		return ((rtn == -1) ? 0 : rtn);
}
