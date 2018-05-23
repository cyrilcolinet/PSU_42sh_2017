/*
** EPITECH PROJECT, 2018
** list_to_array
** File description:
** util
*/

#include "42.h"

void free_list_to_str(env_t *env)
{
	int	i = 0;

	if (!env->str_env)
		return;
	while (env->str_env[i]) {
		free(env->str_env[i]);
		i++;
	}
	env->str_env = NULL;
}

char **my_list_to_array(env_t *env)
{
	int list_size = my_list_size(env);
	char **array = malloc(sizeof(char *) * (list_size + 1));
	int i = 0;
	listenv_t *listenv_temp = env->listenv;

	while (listenv_temp) {
		array[i] = NULL;
		array[i] = my_strcat_malloc(array[i], listenv_temp->line);
		listenv_temp = listenv_temp->next;
		i++;
	}
	array[i] = NULL;
	return array;
}