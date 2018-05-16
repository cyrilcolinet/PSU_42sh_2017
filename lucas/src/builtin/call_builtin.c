/*
** EPITECH PROJECT, 2018
** call
** File description:
** minishell
*/

#include "minishell.h"

void call_builtins(int func, char **av, env_t *env)
{
	switch (func) {
	case 0:
		my_cd(av, env);
		break;
	case 1:
		my_setenv_cmd(env, av);
		break;
	case 2:
		my_unsetenv_cmd(env, av);
		break;
	case 3:
		my_env(env);
		break;
	case 4:
		exit_success(av, env);
		break;
	default:
		return;
	}
}
