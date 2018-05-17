/*
** EPITECH PROJECT, 2018
** 42
** File description:
** globbing
*/

#include "42.h"

int	valid_globbing_interval(char *file, char *interval)
{
	int	err = 0;

	for (int i = (int)interval[0]; i < (int)interval[1]; i++) {
		err += ((int)file[0] == i) ? 1 : 0;
	}
	return (err == 0) ? -1 : 1;
}

int	valid_globbing_extension(char *file, char *extension)
{
	for (int i = 0; file[i]; i++) {
		if (strcmp(&file[i], extension) == 0)
			return 1;
	}
	return -1;
}

int	valid_globbing_file(char *file, char *extension, char *interval)
{
	if (interval && valid_globbing_interval(file, interval) == -1)
		return -1;
	if (extension && valid_globbing_extension(file, extension) == -1)
		return -1;
	return 1;
}