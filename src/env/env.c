/*
** EPITECH PROJECT, 2018
** env
** File description:
** 42
*/

#include "42.h"

char *env_get_variable(char *variable, env_t *env)
{
	listenv_t *tmp = env->listenv;

	while (tmp->next != NULL) {
		if (my_strequ(tmp->next->var, variable))
			return (tmp->next->content);
		tmp = tmp->next;
	}

	return ("");
}

void my_env(env_t *env, char **av)
{
	listenv_t *tmp = env->listenv;
	(void)av;

	while (tmp->next != NULL) {
		my_putstr(tmp->next->var);
		my_putstr("=");
		my_putstr(tmp->next->content);
		my_putstr("\n");
		tmp = tmp->next;
	}
}
