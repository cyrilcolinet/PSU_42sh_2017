/*
** EPITECH PROJECT, 2018
** call
** File description:
** 42
*/

#include "42.h"

void call_builtins(int func, char **av, env_t *env)
{
	void (*builtins[7])(env_t *, char **) = {
		my_cd, my_setenv_cmd, my_unsetenv_cmd, my_env, exit_success,
		my_echo
	};

	builtins[func](env, av);
}
