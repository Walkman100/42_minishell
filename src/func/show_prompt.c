/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:45:39 by mcarter           #+#    #+#             */
/*   Updated: 2019/09/24 15:04:42 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	put_hostname(char full_name)
{
	if (full_name)
		system("hostname");
	else
		system("hostname -s");
}

void	put_username(char **envp)
{
	ft_putstr(get_envvar(envp, "USER="));
}

void	put_cwd(char **envp)
{
	ft_putstr(get_envvar(envp, "PWD="));
}

void	show_prompt(char **envp)
{
	char	*ps1;

	ps1 = get_envvar(envp, "PS1=");
	if (!ps1)
	{
		ft_putstr("$ > ");
		return ;
	}
	while (*ps1)
	{
		if (*ps1 == '\\')
		{
			ps1++;
			if (*ps1 == 'a')
				ft_putchar('\a');
			else if (*ps1 == 'e')
				ft_putchar('\e');
			else if (*ps1 == 'n')
				ft_putchar('\n');
			else if (*ps1 == 'r')
				ft_putchar('\r');
			else if (*ps1 == '\\')
				ft_putchar('\\');
			else if (*ps1 == 'h')
				put_hostname(0);
			else if (*ps1 == 'H')
				put_hostname(1);
			else if (*ps1 == 'u')
				put_username(envp);
			else if (*ps1 == 'w')
				put_cwd(envp); // cwd, $HOME to ~
			// else if (*ps1 == '$')
			// 	ft_putchar('\$'); // # if UID = 0, otherwise $
			else if (*ps1 == '[' || *ps1 == ']')
				;
			else
				ft_putchar(*ps1);
		}
		else
			ft_putchar(*ps1);
		ps1++;
	}
}
