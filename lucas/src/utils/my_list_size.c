/*
** EPITECH PROJECT, 2018
** list size
** File description:
** utils
*/

#include "minishell.h"

int my_list_size(env_t *env)
{
	int i = 0;
	listenv_t *listenv_temp = env->listenv;

	while (listenv_temp) {
		i++;
		listenv_temp = listenv_temp->next;
	}
	return i;
}
