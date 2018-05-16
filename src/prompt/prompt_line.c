/*
** EPITECH PROJECT, 2018
** prompt
** File description:
** 42
*/

#include "42.h"

char *get_cdir(env_t env)
{
	int i = 0;
	int j = 0;
	int separator = 0;

	while (env.pwd_path[i]) {
		if (env.pwd_path[i] == '/')
			separator++;
		i++;
	}
	i = 0;
	while (env.pwd_path[i]) {
		if (env.pwd_path[i] == '/')
			j++;
		if (j == separator)
			return &env.pwd_path[i + 1];
		i++;
	}
	return NULL;
}

void prompt(env_t env)
{
	char *path = get_cdir(env);

	if (isatty(0) == 1) {
		my_putstr("[");
		my_putstr(env.usr_name);
		my_putstr("@\e[92mMinishell\e[0m ");
		my_putstr(path);
		my_putstr("]$ > ");
	}
}
