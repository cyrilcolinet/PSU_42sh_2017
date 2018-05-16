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

int exec_err(char *cmd, pid_t pid)
{
	char cwd[256];
	char *tmp = NULL;
	char *path_cmd = NULL;

	getcwd(cwd, sizeof(cwd));
	tmp = my_strcat_malloc(cwd, "/");
	path_cmd = my_strcat_malloc(tmp, &cmd[2]);
	if (is_file(path_cmd) == -1) {
		my_putstr_err(cmd);
		my_putstr_err(": Permission denied.\n");
		kill(pid, SIGKILL);
	}
	free(tmp);
	free(path_cmd);
	return 0;
}
