/*
** EPITECH PROJECT, 2018
** env cmd
** File description:
** minishell
*/

#include "minishell.h"

void extra_args(int nb_arg, char **av, env_t *env)
{
	if (nb_arg == 2) {
		if (posix_bug(av[1], env) == 0)
			return;
		add_env(env, av[1], "");
		return;
	}
	if (nb_arg == 1) {
		my_env(env);
		return;
	}
}

void my_setenv_cmd(env_t *env, char **av)
{
	int nb_arg = my_array_size(av);
	int env_var;

	if (nb_arg != 3) {
		extra_args(nb_arg, av, env);
		update_env(env);
		update_path(env);
		return;
	}
	if (posix_bug(av[1], env) == 0)
		return;
	env_var = name_exist(env, av[1]);
	if (env_var == 0)
		add_env(env, av[1], av[2]);
	else
		change_env(env, av[1], av[2]);
	update_env(env);
	update_path(env);
}
