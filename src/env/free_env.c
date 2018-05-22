/*
** EPITECH PROJECT, 2018
** free
** File description:
** env
*/

#include "42.h"

void free_env(env_t *env)
{
	free_history(env);
	free_listenv(env);
	free_syspath(env);
	my_freetab(env->str_env);
	free(env->usr_name);
	free(env->bashrc_path);
	free(env->pwd_path);	
	free(env->pwdold_path);
	free(env);
}
