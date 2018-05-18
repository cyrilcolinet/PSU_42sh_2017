/*
** EPITECH PROJECT, 2018
** 42
** File description:
** var
*/
#include "42.h"

char	*find_variable(env_t *env, char *name)
{
	shell_var_t	*tmp = env->shell_var;

	while (tmp) {
		printf("compare %s with %s\n", tmp->var_name, name);
		if (my_strcmp(tmp->var_name, name) == 0)
			return tmp->var_value;
		tmp = tmp->next;
	}
	return NULL;
}