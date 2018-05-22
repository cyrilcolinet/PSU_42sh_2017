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
	switch (func) {
	case 0:
		my_cd(env, av);
		break;
	case 1:
		my_setenv_cmd(env, av);
		break;
	case 2:
		my_unsetenv_cmd(env, av);
		break;
	case 3:
		my_env(env, av);
		break;
	case 4:
		exit_success(env, av);
		break;
	case 5:
		my_echo(env, av);
		break;
	default:
		return;
	}
}
