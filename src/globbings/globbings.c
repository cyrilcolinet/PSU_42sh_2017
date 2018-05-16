/*
** EPITECH PROJECT, 2018
** 42
** File description:
** globbing
*/

#include "42.h"

char	*perform_globbing(char *cmd, char type)
{
	char	*interval = search_interval(cmd);
	char	*extension = search_extension(cmd, type);
	char	*globbing = NULL;

	(void)extension;
	(void)globbing;
	printf("globbing with type: %c ", type);
	if (interval)
		printf("[ %d - %d ]", interval[0], interval[1]);
	printf("\n");
	return NULL;
}

char	*apply_globbing(char *cmd)
{
	char	type;
	char	*glob_cmd = NULL;

	if (!cmd)
		return NULL;
	type = is_globbing(cmd);
	if (type) {
		glob_cmd = perform_globbing(cmd, type);
	}
	(void)glob_cmd;
	return NULL;
}