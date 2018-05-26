/*
** EPITECH PROJECT, 2018
** error
** File description:
** messages
*/

#include "42.h"

void cd_err(char *cmd)
{
	if (access(cmd, F_OK) == -1) {
		my_putstr_err(cmd);
		my_putstr_err(": No such file or directory.\n");
		return;
	}
	if (is_file(cmd) == 1) {
		my_putstr_err(cmd);
		my_putstr_err(": Not a directory.\n");
	}
}

int exec_err(char *cmd, env_t *env)
{
	if (errno == EACCES) {
		my_putstr_err(cmd);
		my_putstr_err(": Permission denied.\n");
	} else if (errno == ENOEXEC) {
		my_putstr_err(cmd);
		my_putstr_err(": Exec format error. ");
		my_putstr_err("Wrong Architecture.\n");
	}

	env->exit_code = 1;
	return 0;
}
