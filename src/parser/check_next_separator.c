/*
** EPITECH PROJECT, 2018
** check_next_separator
** File description:
** 42
*/

#include "shell.h"

int	check_next_separator(char **line, int i)
{
	if (line[i + 1] == NULL)
		return (0);
	if (line[i + 1][0] != '\0' && line[i + 1][0] == '&'
	&& line[i + 1][1] != '\0' && line[i + 1][1] == '&'
	&& line[i + 1][2] == '\0')
		return (1);
	if (line[i + 1][0] != '\0' && line[i + 1][0] == '|'
	&& line[i + 1][1] != '\0' && line[i + 1][1] == '|'
	&& line[i + 1][2] == '\0')
		return (2);
	return (0);
}
