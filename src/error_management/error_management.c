/*
** EPITECH PROJECT, 2018
** error_management
** File description:
** 42
*/

#include "42.h"

static int pass_quote(char *s, int i, char delim)
{
	i++;
	while (s[i] != delim) {
		i++;
	}
	return (i);
}

static bool check_invalid_null_command(char *s)
{
	if (s[0] == '|')
		return (false);
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == 34) {
			i = pass_quote(s, i, 34);
		continue;
		} else if (s[i] == 39) {
			i = pass_quote(s, i, 39);
		continue;
		}
		if (s[i] == '|' && (s[i + 1] == '\0'
		|| (s[i + 1] != '\0' && s[i + 1] == ' '
		&& (s[i + 2] == '|' || s[i + 2] == ';'
		|| s[i + 2] == '&'))))
			return (false);
	}
	return (true);
}

static bool check_unmatched(char *s)
{
	int quote = 1;
	int dquote = 1;

	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == 34 && quote == 1)
			dquote *= -1;
		if (s[i] == 39 && dquote == 1)
			quote *= -1;
	}
	if (dquote == -1 || quote == -1) {
		my_putstr("Unmatched '");
		if (quote == -1)
			my_putchar(39);
		else if (dquote == -1)
			my_putchar(34);
		my_putstr("'.\n");
		return (false);
	}
	return (true);
}

bool error_management(char *s)
{
	if (!check_unmatched(s))
		return (false);
	if (!check_invalid_null_command(s)) {
		my_putstr("Invalid null command.\n");
		return (false);
	}
	return (true);
}
