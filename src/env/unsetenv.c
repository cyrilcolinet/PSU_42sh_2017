/*
** EPITECH PROJECT, 2018
** unset
** File description:
** minishell
*/

#include "minishell.h"

int delete_env_name(listenv_t **head, char *name)
{
	int len = my_strlen(name);
	listenv_t *listenv_tmp = *head;
	listenv_t *listenv_prev;

	if (listenv_tmp && my_strncmp(listenv_tmp->line, name, len) == 0) {
		*head = listenv_tmp->next;
		return 0;
	}
	while (listenv_tmp) {
		if (my_strncmp(listenv_tmp->line, name, len) == 0) {
			listenv_prev->next = listenv_tmp->next;
			return 0;
		}
		listenv_prev = listenv_tmp;
		listenv_tmp = listenv_tmp->next;
	}
	return 0;
}

int my_unsetenv(env_t *env, char *name)
{
	int error = 0;

	if (name_exist(env, name) == 0)
		return 1;
	error = delete_env_name(&env->listenv, name);
	update_env(env);
	if (error == -1) {
		write(1, "unsetenv: Too few arguments.\n", 29);
		env->exit_code = 1;
	}
	return error;
}
