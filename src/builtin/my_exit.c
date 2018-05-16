/*
** EPITECH PROJECT, 2018
** exit
** File description:
** 42
*/

#include "42.h"

void exit_success(char **av, env_t *env)
{
	int status = 0;
	int len = my_array_size(av);

	if (len == 2) {
		if (env)
			free(env);
		status = my_atoi(av[1]);
		exit(status);
	} else if (len == 1) {
		if (env)
			free_env(env);
		exit(env->exit_code);
	} else if (len > 2)
		my_putstr_err("exit: Expression Syntax.\n");
}
