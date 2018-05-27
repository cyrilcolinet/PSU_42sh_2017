/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** get_next_line chooser
*/

# include "shell.h"

char *default_gnl(env_t *env)
{
	(void)env;

	return (get_next_line(0));
}
