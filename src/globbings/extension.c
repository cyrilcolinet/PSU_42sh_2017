/*
** EPITECH PROJECT, 2018
** 42
** File description:
** globbing
*/

#include "42.h"

char	*search_extension(char *cmd, char type)
{
	char	**array = my_strtok(cmd, type);

	if (array && my_array_size(array) == 2) {
		return array[1];
	}
	return NULL;
}