/*
** EPITECH PROJECT, 2018
** 42
** File description:
** globbing
*/

#include "42.h"
#include "globbing.h"

int	is_interval(char *cmd)
{
	int	i = 0;

	for (i; cmd[i] && cmd[i] != '-'; i++);
	if (cmd[i] == '\0')
		return -1;
	for (i; cmd[i] && cmd[i] != ']'; i++);
	if (cmd[i] == '\0')
		return -1;
	return 1;
}

char	get_next_letter(char *cmd, int offset)
{
	int	i = 0;
	if (offset == 1)
		for (i = 0; cmd[i] && cmd[i] != '-'; i++);
	if (cmd[i] == '\0')
		return '\0';
	for (i = 0; cmd[i]; i++) {
		if (cmd[i] != 32 && cmd[i] != '-')
			return cmd[i];
	}
}

char	*search_interval(char *cmd)
{
	char	*interval = malloc(sizeof(char) * 2);
	int	i = 0;

	for (i; cmd[i] && cmd[i] != '['; i++);
	if (cmd[i] == '\0')
		return NULL;
	cmd = &cmd[i];
	printf("get: $%s\n", cmd);
	if (is_interval(cmd) == 1) {
		interval[0] = get_next_letter(cmd, 0);
		interval[1] = get_next_letter(cmd, 1);
		interval[2] = '\0';
		return interval;
	}
	free(interval);
	return NULL;
}