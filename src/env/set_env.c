/*
** EPITECH PROJECT, 2018
** set_env
** File description:
** minishell
*/

#include "minishell.h"

int name_exist(env_t *env, char *name)
{
	int len = my_strlen(name);
	listenv_t *listenv_tmp = env->listenv;

	while (listenv_tmp) {
		if (my_strncmp(listenv_tmp->line, name, len) == 0)
			return 1;
		listenv_tmp = listenv_tmp->next;
	}
	return 0;
}

int posix_bug(char *name, env_t *env)
{
	int i = 0;

	if (my_strlen(name) == 0 || (name[0] >= '0' && name[0] <= '9')) {
		my_putstr("setenv: Variable name must begin");
		my_putstr(" with a letter.\n");
		env->exit_code = 1;
		return 0;
	}
	while (name && name[i]) {
		if (name[i] == '=') {
			my_putstr("setenv: Variable name must ");
			my_putstr("contain alphanumeric characters.\n");
			env->exit_code = 1;
			return 0;
		}
		i++;
	}
	return 1;
}

int add_env(env_t *env, char *name, char *value)
{
	char *line = my_strcat_malloc(name, "=");

	line = my_strcat_malloc(line, value);
	if (line == NULL)
		return -1;
	add_line(&env->listenv, line);
	free(line);
	return 0;
}

int change_env(env_t *env, char *name, char *value)
{
	int len = my_strlen(name) - 1;
	listenv_t *listenv_tmp = env->listenv;
	char *new_line = my_strcat_malloc(name, "=");
	char *final_line = NULL;

	final_line = my_strcat_malloc(new_line, value);
	free(new_line);
	while (listenv_tmp) {
		if (my_strncmp(listenv_tmp->line, name, len) == 0) {
			listenv_tmp->line = my_strcat_malloc(NULL,
					final_line);
			free(final_line);
			return 0;
		}
		listenv_tmp = listenv_tmp->next;
	}
	return -1;
}

int my_setenv(env_t *env, char *name, char *value, int overwrite)
{
	int error = 0;

	if (posix_bug(name, env) == 0)
		return -1;
	if (name_exist(env, name) == 0 && overwrite == 0) {
		error = add_env(env, name, value);
		return error;
	} else if (overwrite != 0) {
		change_env(env, name, value);
		return error;
	}
	return error;
}
