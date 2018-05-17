/*
** EPITECH PROJECT, 2018
** 42
** File description:
** globbing
*/

#include "42.h"

char	*find_path_in_array(char **array)
{
	int		i = 0;
	struct stat	sb;

	while (array && array[i]) {
		stat(array[i], &sb);
		if (access(array[i], F_OK) == 0
			&& S_ISDIR(sb.st_mode))
			return strdup(array[i]);
		i++;
	}
	return NULL;
}

char	*search_path(char *cmd, char type)
{
	char	**array = my_strtok(cmd, type);
	char	**before_globbing = NULL;
	char	*path = NULL;

	if (array && my_array_size(array) == 2) {
		before_globbing = my_strtok(array[0], ' ');
		my_freetab(array);
		path = find_path_in_array(before_globbing);
		my_freetab(before_globbing);
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