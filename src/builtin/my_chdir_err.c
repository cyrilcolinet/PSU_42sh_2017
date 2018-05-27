/*
** EPITECH PROJECT, 2018
** chdir err
** File description:
** 42
*/

# include "shell.h"

int is_file(char *path)
{
	struct stat sb;

	stat(path, &sb);
	return (S_ISDIR(sb.st_mode) ? -1 : 1);
}
