/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_from_envp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:04:42 by mcarter           #+#    #+#             */
/*   Updated: 2019/09/24 14:23:31 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**get_path_from_envp(char **envp)
{
	char	**path_arr;
	MAXUNBR	arr_count;
	MAXUNBR	curr_len;
	MAXUNBR	i;

	while (*envp && !ft_strnequ(*envp, "PATH=", 5))
		envp++;
	if (!*envp)
	{
		path_arr = ft_memalloc(1);
		return (path_arr);
	}
	*envp += 5;
	arr_count = ft_chrcount(*envp, ':');
	path_arr = ft_memalloc(sizeof(char *) * (arr_count + 2));
	i = 0;
	while (i < arr_count)
	{
		curr_len = ft_strclen(*envp, ':');
		path_arr[i] = ft_strsub(*envp, 0, curr_len);
		*envp += curr_len + 1;
		i++;
	}
	path_arr[i] = ft_strdup(*envp);
	return (path_arr);
}
