/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:45:37 by mcarter           #+#    #+#             */
/*   Updated: 2019/09/25 11:21:55 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_input(void)
{
	char			*rtn;
	ssize_t			ret;

	ret = get_next_line(STDIN_FILENO, &rtn);
	if (ret == 0 || ret == -1)
		return (NULL);
	return (rtn);
}
