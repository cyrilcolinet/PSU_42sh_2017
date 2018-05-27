/*
** EPITECH PROJECT, 2018
** update_env
** File description:
** 42
*/

# include "shell.h"

void update_path(env_t *env)
{
	char **str_tmp = my_list_to_array(env);

	env->syspath = init_syspath(env_get_variable(S_BINPATH, env));
	free(str_tmp);
}

void update_env(env_t *env)
{
	char **str_tmp = my_list_to_array(env);

	env->usr_name = NULL;
	env->usr_name = env_get_variable(S_USR, env);
	free(str_tmp);
}
