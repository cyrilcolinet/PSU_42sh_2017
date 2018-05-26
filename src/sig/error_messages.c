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

int exec_err(char *cmd, pid_t pid, env_t *env)
{
	char cwd[256];
	char *tmp = NULL;
	char *path_cmd = NULL;

	getcwd(cwd, sizeof(cwd));
	tmp = my_strcat_malloc(cwd, "/");
	path_cmd = my_strcat_malloc(tmp, &cmd[2]);
	my_putstr(cmd);
	if (is_file(path_cmd) == -1) {
		my_putstr(": Permission denied.\n");
		//kill(pid, SIGKILL);
	} else {
		my_putstr_err(": Exec format error. ");
		my_putstr_err("Binary file not executable.\n");
	}
	env->exit_code = 1;
	free(tmp);
	free(path_cmd);
	return 0;
}
