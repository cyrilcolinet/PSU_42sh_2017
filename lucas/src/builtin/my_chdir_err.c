/*
** EPITECH PROJECT, 2018
** chdir err
** File description:
** minishell
*/

#include "minishell.h"

int is_file(char *path)
{
	struct stat sb;

	stat(path, &sb);
	return (S_ISDIR(sb.st_mode) ? -1 : 1);
}
