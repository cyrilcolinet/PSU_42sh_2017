/*
** EPITECH PROJECT, 2018
** exit
** File description:
** 42
*/

#include "42.h"

void exit_success(env_t *env, char **av)
{
	int status = 0;
	int len = my_array_size(av);

	if (len == 2) {
		status = my_atoi(av[1]);
		my_freetab(av);
		exit(status);
	} else if (len == 1) {
		status = env->exit_code;
		if (env) {
			free_env(env);
		}
		my_freetab(av);
		exit(status);
	} else if (len > 2)
		my_putstr_err("exit: Expression Syntax.\n");
}
