/*
** EPITECH PROJECT, 2017
** functions.c
** File description:
** Made by developers
*/

#include "42.h"

void		my_cd_exec(t_mini *control)
{
	char	cwd[SIZE_BUFF];

	if (my_strstr(control->args[1], "-") == 0
		&& my_get_env(*control, "OLDPWD") != NULL) {
		control->args[1] = my_get_env(*control, "OLDPWD");
	}
	if (my_strstr(control->args[1], "~") == 0
		&& my_get_env(*control, "HOME") != NULL)
		control->args[1] = my_get_env(*control, "HOME");
	my_set_env(control, "OLDPWD", my_get_env(*control, "PWD"));
	if (chdir(control->args[1]) == -1)
		my_print_cd_err(control);
	else {
		getcwd(cwd, SIZE_BUFF);
		my_set_env(control, "PWD", cwd);
	}
}

void		my_cd(t_mini *control)
{
	if (!my_str_start(control->buffer, "cd"))
		return;
	if (my_size_tab(control->args) > 2) {
		my_putstr("cd: Too many arguments.\n", 2);
		control->status = 1;
	} else if (my_size_tab(control->args) == 2)
		my_cd_exec(control);
	control->system = 1;
}

void		my_exit(char *buffer)
{
	if (!my_str_equals(buffer, "exit"))
		return;
	if (isatty(0) != 0)
		my_putstr("exit\n", 1);
	exit(EXIT_SUCCESS);
}
