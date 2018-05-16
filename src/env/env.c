/*
** EPITECH PROJECT, 2018
** env
** File description:
** 42
*/

#include "42.h"

int my_env(env_t *env)
{
	int i = 0;
	listenv_t *temp = env->listenv;

	while (temp) {
		my_putstr(temp->line);
		temp = temp->next;
		my_putchar('\n');
		i++;
	}
	return 0;
}
