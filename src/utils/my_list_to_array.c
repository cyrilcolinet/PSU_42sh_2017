/*
** EPITECH PROJECT, 2018
** list_to_array
** File description:
** util
*/

#include "42.h"

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
