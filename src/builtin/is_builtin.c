/*
** EPITECH PROJECT, 2018
** builtin
** File description:
** 42
*/

#include "42.h"

int is_builtin(char *str)
{
	int i = 0;
	char *builtins[] = {"cd", "setenv", "unsetenv", "env", "exit",
		"echo", "alias", NULL};

	while (builtins[i]) {
		if (my_strcmp(builtins[i], str) == 0)
			return i;
		i++;
	}
	return -1;
}
