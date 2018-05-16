/*
** EPITECH PROJECT, 2018
** check_redirect_error
** File description:
** minishell
*/

#include "minishell2.h"

static bool check_err_1(char *s, int i)
{
	if (s[i + 1] == '<' || (s[i + 1] == ' ' && s[i + 2] == '<')) {
		my_putstr("Invalid null command.\n");
		return (true);
	}
	if (s[i + 1] == '>' || (s[i + 1] == ' ' && s[i + 2] == '>')) {
		my_putstr("Invalid null command.\n");
		return (true);
	}
	return (false);
}

static bool check_err_2(char *s, int i)
{
	if (s[i + 1] == '\0' || (s[i + 1] == '<' || s[i + 1] == ';'
	|| s[i + 1] == '|') || (s[i + 1] == ' ' && (s[i + 2] == '>'
	|| s[i + 2] == ';' || s[i + 2] == '<' || s[i + 2] == '|')))
		return (true);
	return (false);
}

static bool check_err_3(char *s, int i)
{
	if (s[i + 1] == '\0' || (s[i + 1] == '>' || s[i + 1] == ';'
	|| s[i + 1] == '|') || (s[i + 1] == ' ' && (s[i + 2] == '>'
	|| s[i + 2] == ';' || s[i + 2] == '<' || s[i + 2] == '|')))
		return (true);
	return (false);
}

bool check_redirect_error(mysh_t *mysh, char *s)
{
	if (s[0] == '>' || s[0] == '<' || s[0] == '|') {
		my_putstr("Invalid null command.\n");
		return (false);
	}
	for (int i = 0 ; s[i] != '\0'; i++) {
		if (s[i] == ';' && (s[i + 1] != '\0'
		&& check_err_1(s, i))) {
			return (false);
		}
		if (s[i] == '>' && check_err_2(s, i)) {
			my_putstr("Missing name for redirect.\n");
			return (false);
		}
		if (s[i] == '<' && check_err_3(s, i)) {
			my_putstr("Missing name for redirect.\n");
			return (false);
		}
	}
	return (true);
}
