/*
** EPITECH PROJECT, 2018
** env
** File description:
** 42
*/

#include "42.h"

void my_env(env_t *env, char **av)
{
	int i = 0;
	listenv_t *temp = env->listenv;

	(void)av;
	while (temp) {
		my_putstr(temp->line);
		temp = temp->next;
		my_putchar('\n');
		i++;
	}
}
