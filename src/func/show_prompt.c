/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:45:39 by mcarter           #+#    #+#             */
/*   Updated: 2020/01/30 13:29:40 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	put_hostname(char full_name)
{
	static char		hostname[1024];
	unsigned int	i;

	if (!*hostname)
	{
		hostname[1023] = '\0';
		gethostname(hostname, 1023);
	}
	if (full_name)
		ft_putstr(hostname);
	else
	{
		i = 0;
		while (hostname[i] != '\0' && hostname[i] != '.')
		{
			ft_putchar(hostname[i]);
			i++;
		}
	}
}

void	put_cwd(char **envp)
{
	char	*pwd;
	char	*home;
	MAXUNBR	homelen;

	pwd = envvar_get(envp, "PWD=");
	if (!pwd)
		pwd = "";
	home = envvar_get(envp, "HOME=");
	if (!home)
		home = "NOTAVALUE";
	homelen = ft_strlen(home);
	if (ft_strnequ(pwd, home, homelen))
	{
		pwd[0] = '~';
		ft_memmove(pwd + 1, pwd + homelen, ft_strlen(pwd) - homelen + 1);
	}
	ft_putstr(pwd);
}

void	put_uidchar(void)
{
	if (geteuid())
		ft_putchar('$');
	else
		ft_putchar('#');
}

void	put_ps1_delegate(char *ps1, char **envp)
{
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
		ft_putstr(envvar_get(envp, "USER="));
	else if (*ps1 == 'w')
		put_cwd(envp);
	else if (*ps1 == '$')
		put_uidchar();
	else
		ft_putchar(*ps1);
}

void	show_prompt(char **envp)
{
	char	*ps1;

	ps1 = envvar_get(envp, "PS1=");
	if (!ps1)
		return (ft_putstr("MSH $ > "));
	while (*ps1)
	{
		if (*ps1 == '\\')
		{
			ps1++;
			if (ft_strnequ(ps1, "033", 3))
			{
				ft_putchar('\e');
				ps1 += 2;
			}
			else if (*ps1 != '[' && *ps1 != ']')
				put_ps1_delegate(ps1, envp);
		}
		else
			ft_putchar(*ps1);
		ps1++;
	}
}
