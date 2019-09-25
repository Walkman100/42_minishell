/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:59:42 by mcarter           #+#    #+#             */
/*   Updated: 2019/09/25 13:53:32 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

unsigned char	is_builtin(char *name)
{
	if (ft_strequ(name, "echo") || ft_strequ(name, "exit") ||
		ft_strequ(name, "clear") || ft_strequ(name, "cd") ||
		ft_strequ(name, "pwd") || ft_strequ(name, "setenv") ||
		ft_strequ(name, "unsetenv") || ft_strequ(name, "env"))
		return (1);
	else
		return (0);
}

void			replace_vars(char **str, char **envp)
{
	char			*varnamestart;
	unsigned int	varnamelen;
	char			*tmpvarname;
	char			*tmpvarcontents;
	char			*newstr;

	while ((varnamestart = ft_strchr(*str, '$')))
	{
		varnamestart++;
		varnamelen = 0;
		while (ft_isalnum(varnamestart[varnamelen]))
			varnamelen++;
		tmpvarname = ft_strnew(varnamelen);
		ft_strncpy(tmpvarname, varnamestart, varnamelen);
		tmpvarname[varnamelen] = '=';
		tmpvarcontents = get_envvar(envp, tmpvarname);
		newstr = ft_strnew(ft_strlen(*str) -
							ft_strlen(tmpvarname) + ft_strlen(tmpvarcontents));
		ft_strncpy(newstr, *str, ft_strclen(*str, '$'));
		ft_strcat(newstr, tmpvarcontents);
		ft_strcat(newstr, varnamestart + varnamelen);
		ft_strdel(&tmpvarname);
		ft_strdel(str);
		*str = newstr;
	}
}

t_userinput		parse_input(char *input, char **envp)
{
	t_userinput rtn;
	MAXUNBR		separator_pos;

	separator_pos = ft_strclen(input, ' ');
	rtn.program_name = ft_strsub(input, 0, separator_pos);
	replace_vars(&(rtn.program_name), envp);
	if (ft_strchr(input, ' '))
	{
		rtn.program_args = ft_strdup(input + separator_pos + 1);
		replace_vars(&(rtn.program_args), envp);
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
