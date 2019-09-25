/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:59:42 by mcarter           #+#    #+#             */
/*   Updated: 2019/09/25 12:36:34 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_userinput	parse_input(char *input)
{
	t_userinput rtn;
	MAXUNBR		separator_pos;

	separator_pos = ft_strclen(input, ' ');
	rtn.program_name = ft_strsub(input, 0, separator_pos);
	if (ft_strchr(input, ' '))
		rtn.program_args = input + separator_pos + 1;
	else
		rtn.program_args = NULL;
	if (ft_strequ(rtn.program_name, "echo") ||
		ft_strequ(rtn.program_name, "exit") ||
		ft_strequ(rtn.program_name, "clear") ||
		ft_strequ(rtn.program_name, "cd") ||
		ft_strequ(rtn.program_name, "pwd") ||
		ft_strequ(rtn.program_name, "setenv") ||
		ft_strequ(rtn.program_name, "unsetenv") ||
		ft_strequ(rtn.program_name, "env"))
		rtn.is_builtin = 1;
	else
		rtn.is_builtin = 0;
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
