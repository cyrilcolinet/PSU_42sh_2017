/*
** EPITECH PROJECT, 2017
** minishell.h
** File description:
** Made by developers
*/

#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <wait.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"

#define SIZE_BUFF 4096

typedef struct
{
	char	**env;
	char	**cmds;
	char	**args;
	char	*buffer;
	pid_t	pid;
	int	status;
	int	system;
}	t_mini;

/*	COMMANDS.C	*/
void		my_cd(t_mini*);
void            my_prompt(void);
void		my_exit(char*);

/*	ENV.C		*/
void		my_env(t_mini*);
char		**my_copy_env(char**, int);
char		*my_get_env(t_mini, char const*);
int		my_set_env(t_mini*, char*, char*);
void		my_unset_env(t_mini*, char*);

/*	ENV2.C		*/
void		my_env2(t_mini*);

/*	MINISHELL.C	*/
void		my_pid(t_mini*);
void		my_exec_prompt(t_mini*);

/*	ERRORS.C	*/
void		my_check_errors(t_mini*);
void		my_execve(t_mini*);

/*	MY_STR_TO_WORD_ARRAY.C	*/
char		**my_str_to_word_array(char*, char);

/*	UTILS.C		*/
int		my_strstr(char*, char*);
char		*my_strcat(char const*, char const*, int);
int		my_str_start(char const*, char const*);
void		my_print_cd_err(t_mini*);
int		my_str_equals(char const*, char const*);

/*	UTILS2.C	*/
int		my_str_alpha(char const*);
char		*my_remove_tabs(char*);

#endif
