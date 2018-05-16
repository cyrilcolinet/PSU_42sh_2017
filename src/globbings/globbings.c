/*
** EPITECH PROJECT, 2018
** 42
** File description:
** globbing
*/

#include "42.h"
#include "globbing.h"

char	*perform_globbing(char *cmd, char type)
{
	char	*interval = search_interval(cmd);

	printf("globbing with type: %c ", type);
	if (interval)
		printf("[ %d - %d ]", interval[0], interval[1]);
	printf("\n");
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
}