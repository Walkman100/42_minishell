/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:03:45 by mcarter           #+#    #+#             */
/*   Updated: 2019/10/21 15:00:03 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_pwd(char *args)
{
	char	cwd[1024];

	if (getcwd(cwd, 1023))
		ft_putendl(cwd);
	else
		perror("minishell: pwd: ");
}
