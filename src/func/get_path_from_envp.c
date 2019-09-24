/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_from_envp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:04:42 by mcarter           #+#    #+#             */
/*   Updated: 2019/09/24 15:06:49 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**get_path_from_envp(char **envp)
{
	char	*path_var;
	char	**path_arr;
	MAXUNBR	arr_count;
	MAXUNBR	curr_len;
	MAXUNBR	i;

	path_var = get_envvar(envp, "PATH=");
	if (!path_var)
	{
		path_arr = ft_memalloc(1);
		return (path_arr);
	}
	arr_count = ft_chrcount(path_var, ':');
	path_arr = ft_memalloc(sizeof(char *) * (arr_count + 2));
	i = 0;
	while (i < arr_count)
	{
		curr_len = ft_strclen(path_var, ':');
		path_arr[i] = ft_strsub(path_var, 0, curr_len);
		path_var += curr_len + 1;
		i++;
	}
	path_arr[i] = ft_strdup(path_var);
	return (path_arr);
}
