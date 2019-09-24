/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:43:26 by mcarter           #+#    #+#             */
/*   Updated: 2019/09/24 15:17:02 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>    /* ???? - in man 2 read */
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include "../libft/libft.h"

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct rusage	t_rusage;

typedef struct	s_userinput
{
	char			*program_name;
	char			*program_args;
	unsigned char	is_builtin : 1;
	unsigned char	redirect_type : 2;
}				t_userinput;

char			*get_envvar(char **envp, char *varname);
char			**get_path_from_envp(char **envp);
void			show_prompt(char **envp);
char			*get_input(void);
t_userinput		parse_input(char *input);
void			run_function(t_userinput userinput, char **envp);
char			*get_path(char **path, char *program_name);
pid_t			run_program(char *program_path, t_userinput userinput);
void			wait_for_pid(pid_t pid);
#endif
