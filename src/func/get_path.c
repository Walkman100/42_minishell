/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:45:33 by mcarter           #+#    #+#             */
/*   Updated: 2019/10/22 13:46:30 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		check_folder_for_file(char *path, char *filename)
{
	DIR			*dirp;
	t_dirent	*dir_ent;

	if (!(dirp = opendir(path)))
		return (0);
	errno = 0;
	while ((dir_ent = readdir(dirp)) != NULL)
	{
		if (!errno && ft_strequ(dir_ent->d_name, filename))
			return (1);
	}
	closedir(dirp);
	return (0);
}

char	*get_path(char **path, char *program_name)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (check_folder_for_file(path[i], program_name))
			return (ft_strjoin3(path[i], "/", program_name));
		i++;
	}
	return (program_name);
}
