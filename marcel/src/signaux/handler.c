/*
** EPITECH PROJECT, 2018
** handler
** File description:
** minishell
*/

#include "minishell2.h"

void handler_int(int sig)
{
	my_putstr("\n");
	if (isatty(0))
		my_putstr("$> ");
	signal(SIGINT, handler_int);
}
