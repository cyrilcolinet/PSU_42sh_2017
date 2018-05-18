/*
** EPITECH PROJECT, 2018
** 42
** File description:
** var
*/
#include "42.h"

void	apply_local_variables(char ***cmd, env_t *env)
{
	char	**tmp = *cmd;
	char	*var = NULL;

	for (int i = 0; tmp && tmp[i]; i++) {
		if (tmp[i][0] == '$') {
			tmp[i] = (var = find_variable(env, &tmp[i][1])) ?
				var : tmp[i];
		}
	}
}