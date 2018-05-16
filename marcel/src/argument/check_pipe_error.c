/*
** EPITECH PROJECT, 2018
** check_pipe_error
** File description:
** minishell
*/

#include "minishell2.h"

static bool check_err_1(char *s, int i)
{
	if (s[i + 1] == '|' || (s[i + 1] == ' ' && s[i + 2] == '|')) {
		my_putstr("Invalid null command.\n");
		return (true);
	}
	return (false);
}

static bool check_err_2(char *s, int i)
{
	if (s[i + 1] == '\0' || (s[i + 1] == '|' || (s[i + 1] == ' '
	&& s[i + 2] == '|')) || (s[i + 1] == ';'
	|| (s[i + 1] == ' ' && s[i + 2] == ';'))) {
			my_putstr("Invalid null command.\n");
		return (true);
	}
	return (false);
}

static bool check_err_3(char *s, int i)
{
	if ((s[i + 1] == '<' || s[i + 1] == '>') ||
	(s[i + 1] == ' '  && (s[i + 2] == '<' || s[ i + 2] == '>')))
		return (true);
	return (false);
}

static bool is_first_redirect(char *s, int x)
{
	int nb = 0;

	for (int i = 0; i < x; i++) {
		if (s[i] == '>')
			nb++;
	}
	if (nb == 0)
		return (true);
	return (false);
}

bool check_pipe_error(mysh_t *mysh, char *s)
{
	if (s[0] == '|') {
		my_putstr("Invalid null command.\n");
		return (false);
	}
	for (int i = 0 ; s[i] != '\0'; i++) {
		if (s[i] == ';' && (s[i + 1] != '\0' && check_err_1(s, i)))
			return (false);
		if (s[i] == '|' && check_err_2(s, i))
			return (false);
		if (s[i] == '|' && check_err_3(s, i)) {
			if (i != 0 && is_first_redirect(s, i))
				my_putstr("Ambigous input redirect.\n");
			else
				my_putstr("Ambigous output redirect.\n");
			return (false);
		}
	}
	return (true);
}
