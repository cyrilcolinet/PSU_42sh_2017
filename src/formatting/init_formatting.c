/*
** EPITECH PROJECT, 2018
** 42
** File description:
** globbing
*/
#include "42.h"

formatting_t	get_format(char *cmd)
{
	formatting_t	format;

	if (globbing_in_cmd(cmd) == 1)
		format.globbings = get_globbing(cmd);
	return format;
}