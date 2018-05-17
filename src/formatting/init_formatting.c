/*
** EPITECH PROJECT, 2018
** 42
** File description:
** globbing
*/
#include <glob.h>
#include "42.h"

formatting_t	get_defautlt(void)
{
	formatting_t	def;

	def.has_globbings = false;
	return def;
}

formatting_t	get_format(char *cmd)
{
	formatting_t	format;

	format = get_defautlt();
	if (globbing_in_cmd(cmd) == 1) {
		format.has_globbings = true;
	}
	return format;
}