/*
** EPITECH PROJECT, 2018
** init env
** File description:
** 42
*/

#include "42.h"

char *get_env_var(char **av_env, char *var_cmp, int size)
{
	int i = 0;

	while (av_env[i]) {
		if (my_strncmp(av_env[i], var_cmp, size) == 0)
			return &av_env[i][size + 1];
		i++;
	}
	return NULL;
}

env_t init_env(char **av_env)
{
	env_t env;

	env.str_env = av_env;
	env.listenv = init_listenv(av_env);
	env.syspath = init_syspath(get_env_var(av_env, S_BINPATH, 4));
	env.usr_name = get_env_var(av_env, S_USR, 4);
	env.pwd_path = get_env_var(av_env, S_PWD, 3);
	env.pwdold_path = get_env_var(av_env, S_OLDPWD, 6);
	env.exit_code = 0;
	env.history = NULL;
	return env;
}
