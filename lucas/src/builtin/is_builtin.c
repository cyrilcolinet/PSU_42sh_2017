/*
** EPITECH PROJECT, 2018
** builtin
** File description:
** minishell
*/

#include "minishell.h"

int is_builtin(char *str, char **builtins)
{
	int i = 0;

	while (builtins && builtins[i]) {
		if (my_strcmp(builtins[i], str) == 0)
			return i;
		i++;
	}
	return -1;
}
