/*
** EPITECH PROJECT, 2017
** errors.c
** File description:
** Made by developers
*/

#include "minishell.h"

void		my_execve(t_mini *control)
{
	if (execve(control->args[0], control->args, control->env) == -1) {
		if (errno != ENOEXEC)
			return;
		my_putstr(control->args[0], 1);
		my_putstr(": Exec format error.", 1);
		my_putstr(" Wrong Architecture.\n", 1);
	}
}

void		my_check_errors(t_mini *control)
{
	int	t = WTERMSIG(control->status);

	if (!WIFSIGNALED(control->status))
		return;
	if (t == SIGSEGV) {
		my_putstr("Segmentation fault", 1);
		if (WCOREDUMP(control->status))
			my_putstr(" (core dumped)", 1);
		my_putstr("\n", 1);
	} else if (t == SIGFPE) {
		my_putstr("Floating exception", 1);
		if (WCOREDUMP(control->status))
			my_putstr(" (core dumped)", 1);
		my_putstr("\n", 1);
	}
}
