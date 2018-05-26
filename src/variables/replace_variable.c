/*
** EPITECH PROJECT, 2018
** 42
** File description:
** var
*/

#include "42.h"

static char **malloc_doubletab(char **cmd)
{
	char **tmp;
	int count = 0;

	for (int i = 0; cmd[i]; i++)
		count++;
	tmp = malloc(sizeof(char *) * (count + 1));
	tmp[count] = NULL;
	return (tmp);
}

char **apply_local_variables(char **cmd, env_t *env)
{
	char	**tmp = malloc_doubletab(cmd);
	char	*var = NULL;

	for (int i = 0; cmd && cmd[i]; i++) {
		if (cmd[i][0] == '$' &&
		((var = find_variable(env, cmd[i])) != NULL)) {
			tmp[i] = malloc(sizeof(char) *
				(my_strlen(var) + 1));
			tmp[i][my_strlen(var)] = '\0';
			tmp[i] = my_strcpy(tmp[i], var);
		} else {
			tmp[i] = malloc(sizeof(char) *
				(my_strlen(cmd[i]) + 1));
			tmp[i][my_strlen(cmd[i])] = '\0';
			tmp[i] = my_strcpy(tmp[i], cmd[i]);
		}
	}
	my_freetab(cmd);
	return (tmp);
}
