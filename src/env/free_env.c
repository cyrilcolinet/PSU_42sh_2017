/*
** EPITECH PROJECT, 2018
** free
** File description:
** env
*/

#include "42.h"

void free_env(env_t *env)
{
	free_listenv(env);
	free_syspath(env);
}