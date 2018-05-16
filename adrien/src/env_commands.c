/*
** EPITECH PROJECT, 2017
** functions2.c
** File description:
** Made by developers
*/

#include "42.h"

void		my_env(t_mini *control)
{
	int	i = -1;

	if ((my_str_start(control->buffer, "env"))) {
		control->system = 1;
		while (control->env[++i]) {
			my_putstr(control->env[i], 1);
			my_putstr("\n", 1);
		}
	} else if ((my_str_start(control->buffer, "unsetenv"))) {
		control->system = 1;
		if (my_size_tab(control->args) < 2) {
			my_putstr("unsetenv: Too few arguments.\n", 2);
			control->status = 1;
		} else if (my_size_tab(control->args) >= 2) {
			i = 0;
			while (++i < my_size_tab(control->args))
				my_unset_env(control, control->args[i]);
		}
	}
	my_env2(control);
}

void		my_env2(t_mini *control)
{
	int	i = -1;

	if ((my_str_start(control->buffer, "setenv"))) {
		control->system = 1;
		if (my_size_tab(control->args) > 3) {
			my_putstr("setenv: Too many arguments.\n", 2);
			control->status = 1;
		} else if (my_size_tab(control->args) >= 3)
			my_set_env(control, control->args[1], control->args[2]);
		else if (my_size_tab(control->args) >= 2)
			my_set_env(control, control->args[1], "");
		else
			while (control->env[++i]) {
				my_putstr(control->env[i], 1);
				my_putstr("\n", 1);
			}
	}
}
