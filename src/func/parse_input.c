/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:59:42 by mcarter           #+#    #+#             */
/*   Updated: 2020/01/30 14:30:01 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

unsigned char	is_builtin(char *name)
{
	if (ft_strequ(name, "echo") || ft_strequ(name, "exit") ||
			ft_strequ(name, "clear") || ft_strequ(name, "cd") ||
			ft_strequ(name, "pwd") || ft_strequ(name, "setenv") ||
			ft_strequ(name, "unsetenv") || ft_strequ(name, "env") ||
			ft_strequ(name, ".."))
		return (1);
	else
		return (0);
}

char			*str_replace_envvar(char *str, char **envp)
{
	char			*varnamestart;
	unsigned int	varnamelen;
	char			*tmpvarname;
	char			*tmpvarcontents;
	char			*newstr;

	varnamestart = ft_strchr(str, '$');
	varnamestart++;
	varnamelen = 0;
	while (ft_isalnum(varnamestart[varnamelen]) ||
												varnamestart[varnamelen] == '_')
		varnamelen++;
	tmpvarname = ft_strnew(varnamelen + 1);
	ft_strncpy(tmpvarname, varnamestart, varnamelen);
	tmpvarname[varnamelen] = '=';
	if (!(tmpvarcontents = envvar_get(envp, tmpvarname)))
		tmpvarcontents = "";
	newstr = ft_strnew(ft_strlen(str) - ft_strlen(tmpvarname) +
												ft_strlen(tmpvarcontents));
	ft_strncpy(newstr, str, ft_strclen(str, '$'));
	ft_strcat(newstr, tmpvarcontents);
	ft_strcat(newstr, varnamestart + varnamelen);
	ft_strdel(&tmpvarname);
	return (newstr);
}

void			replace_vars(char **str, char **envp)
{
	char			*varnamestart;
	char			*tmpvarcontents;
	char			*newstr;

	while (ft_strchr(*str, '$'))
	{
		newstr = str_replace_envvar(*str, envp);
		ft_strdel(str);
		*str = newstr;
	}
	while ((varnamestart = ft_strchr(*str, '~')))
	{
		if (!(tmpvarcontents = envvar_get(envp, "HOME=")))
			tmpvarcontents = "";
		newstr = ft_strnew(ft_strlen(*str) + ft_strlen(tmpvarcontents) - 1);
		ft_strncpy(newstr, *str, ft_strclen(*str, '~'));
		ft_strcat(newstr, tmpvarcontents);
		ft_strcat(newstr, varnamestart + 1);
		ft_strdel(str);
		*str = newstr;
	}
}

t_userinput		parse_input(char *input, char ***envp)
{
	t_userinput rtn;
	MAXUNBR		separator_pos;

	separator_pos = ft_strclen(input, ' ');
	rtn.program_name = ft_strsub(input, 0, separator_pos);
	replace_vars(&(rtn.program_name), *envp);
	envvar_set(envp, "_=", rtn.program_name);
	if (ft_strchr(input, ' '))
	{
		rtn.program_args = ft_strdup(input + separator_pos + 1);
		replace_vars(&(rtn.program_args), *envp);
	}
	else
		rtn.program_args = NULL;
	rtn.is_builtin = is_builtin(rtn.program_name);
	if (ft_strchr(input, '<'))
		rtn.redirect_type = 0;
	else if (ft_strchr(input, '>'))
	{
		if (ft_strstr(input, ">>"))
			rtn.redirect_type = 2;
		else
			rtn.redirect_type = 1;
	}
	return (rtn);
}
