/*
** EPITECH PROJECT, 2018
** 42
** File description:
** globbing
*/

#include "42.h"

char	*search_path(char *cmd, char type)
{
	char	**array = my_strtok(cmd, type);
	char	*path = NULL;

	if (array && my_array_size(array) == 2) {
		path = strdup(array[1]);
		my_freetab(array);
		return path;
	}
	my_freetab(array);
	return NULL;
}

char	*search_extension(char *cmd, char type)
{
	char	**array = my_strtok(cmd, type);
	char	*extension = NULL;

	if (array && my_array_size(array) == 2) {
		extension = strdup(array[1]);
		my_freetab(array);
		return extension;
	}
	my_freetab(array);
	return NULL;
}