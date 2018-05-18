/*
** EPITECH PROJECT, 2018
** 42
** File description:
** globbing
*/
#include "42.h"

char	contain_globbing(char ltr)
{
	char	typo[] = {'*', '?', '[', ']', '\0'};

	for (int i = 0; typo[i]; i++) {
		if (ltr == typo[i])
			return typo[i];
	}
	return '\0';
}

char	is_globbing(char *cmd)
{
	char	type;

	for (int i = 0; cmd && cmd[i]; i++) {
		type = contain_globbing(cmd[i]);
		if (type)
			return type;
	}
	return '\0';
}

int	globbing_in_cmd(char *cmd)
{
	if (is_globbing(cmd) == '\0')
		return -1;
	return 1;
}