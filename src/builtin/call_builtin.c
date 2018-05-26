/*
** EPITECH PROJECT, 2018
** call
** File description:
** 42
*/

#include "42.h"

void call_builtins(int func, char **av, env_t *env, parser_t *parser)
{
	void (*builtins[7])(env_t *, char **) = {
		my_cd, my_setenv_cmd, my_unsetenv_cmd, my_env,
		my_echo, my_alias
	};
	if (func == 4)
		exit_success(env, av, parser);
	else
		builtins[func](env, av);
}
