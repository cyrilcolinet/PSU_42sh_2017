/*
** EPITECH PROJECT, 2018
** check_access
** File description:
** 42
*/

#include "42.h"

static void command_not_found(char *cmd, char *tmp_cmd)
{
	(void)tmp_cmd;
	my_putstr_err(&cmd[1]);
	my_putstr_err(": Command not found.\n");
}

static char *my_access(env_t *env, char *cmd)
{
	syspath_t *temp = env->syspath;
	char *bin_access = NULL;
	char *tmp_cmd = NULL;

	tmp_cmd = my_strcat_malloc(tmp_cmd, cmd);
	cmd = my_strcat_malloc("/", cmd);
	bin_access = my_strcat_malloc(temp->path, cmd);
	while (temp) {
		if (access(bin_access, F_OK) == 0) {
			free(cmd);
			free(tmp_cmd);
			env->exit_code = 0;
			return bin_access;
		}
		free(bin_access);
		bin_access = my_strcat_malloc(temp->path, cmd);
		temp = temp->next;
	}
	command_not_found(cmd, tmp_cmd);
	return NULL;
}

char *get_path(env_t *env, char *cmd, int *cmd_access)
{
	env->exit_code = 1;
	if (env->syspath == NULL || !cmd) {
		if (cmd) {
			env->exit_code = 1;
			command_not_found(&cmd[1], NULL);
		}
		return NULL;
	}
	if (my_strlen(cmd) > 2 && cmd[0] == '.' && cmd[1] == '/') {
		env->exit_code = 0;
		*cmd_access = 1;
		return cmd;
	}
	if (access(cmd, F_OK) == 0) {
		env->exit_code = 0;
		*cmd_access = 1;
		return cmd;
	}
	return my_access(env, cmd);
}
