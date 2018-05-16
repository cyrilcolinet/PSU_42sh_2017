/*
** EPITECH PROJECT, 2017
** printing.c
** File description:
** Made by developers
*/

#include "42.h"

void		my_prompt(void)
{
	if (isatty(0) != 0)
		my_putstr("$> ", 1);
}

void		my_print_cd_err(t_mini *control)
{
	my_putstr(control->args[1], 2);
	my_putstr(": ", 2);
	my_putstr(strerror(errno), 2);
	my_putstr(".\n", 2);
	control->status = 1;
}
