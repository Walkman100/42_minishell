/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:01:02 by mcarter           #+#    #+#             */
/*   Updated: 2019/09/25 14:31:18 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_echo(char *args)
{
	char	print_newline;

	print_newline = 1;
	if (*args == '-')
	{
		args++;
		while (*args && *args != ' ')
		{
			if (*args == 'n')
				print_newline = 0;
			else
			{
				ft_putstr("echo: Invalid option: ");
				ft_putchar(*args);
				ft_putchar('\n');
				return ;
			}
			args++;
		}
	}
	while (*args == ' ')
		args++;
	ft_putstr(args);
	if (print_newline)
		ft_putchar('\n');
}
