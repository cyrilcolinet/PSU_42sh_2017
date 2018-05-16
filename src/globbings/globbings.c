/*
** EPITECH PROJECT, 2018
** 42
** File description:
** globbing
*/

#include "42.h"

char	*get_file_in_path(void)
{
	return NULL;
}

char	*perform_globbing(char *cmd, char type)
{
	char	*interval = search_interval(cmd);
	char	*extension = search_extension(cmd, type);
	char	*path = search_path(cmd, type);
	char	*globbing = NULL;

	printf("globbing with type: %c ", type);
	if (interval)
		printf("[ %d - %d ]", interval[0], interval[1]);
	printf("extension: %s, path: %s\n", extension, path);
	printf("\n");
	return get_file_in_path();
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