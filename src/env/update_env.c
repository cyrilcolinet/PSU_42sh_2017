/*
** EPITECH PROJECT, 2018
** update_env
** File description:
** 42
*/

#include "42.h"

void update_path(env_t *env)
{
	char **str_tmp = my_list_to_array(env);

	env->syspath = init_syspath(get_env_var(str_tmp, S_BINPATH,
							4));
	free(str_tmp);
}

void update_env(env_t *env)
{
	char **str_tmp = my_list_to_array(env);

	env->usr_name = NULL;
	env->usr_name = get_env_var(str_tmp, S_USR, 4);
	free(str_tmp);
}
