/*
** EPITECH PROJECT, 2018
** is_dir_file
** File description:
** minishell2
*/

#include "minishell2.h"

static bool is_executable(stat_t *info, char *name)
{
	char c;

	c = (info->st_mode & S_IXUSR) ? 'x' : '-';
	if (S_ISREG(info->st_mode) && c == 'x'
	&& (name[0] == '.' && name [1] == '/')) {
		return (true);
	}
	return (false);
}

bool is_dir(mysh_t *mysh, char *name)
{
	stat_t *info = malloc(sizeof(stat_t));

	stat(name, info);
	if ((S_ISDIR(info->st_mode) || S_ISREG(info->st_mode))
	&& !is_executable(info, name)) {
		free(info);
		my_putstr(name);
		mysh->ex_val = 1;
		if (name[0] == '.' && name [1] == '/')
			my_putstr(": Permission denied.\n");
		else
			my_putstr(": Command not found.\n");
		mysh->state = false;
		return (true);
	}
	free(info);
	return (false);
}
