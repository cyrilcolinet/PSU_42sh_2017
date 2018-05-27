/*
** EPITECH PROJECT, 2018
** clear_separator
** File description:
** 42
*/

# include "shell.h"

char *clear_separator(char *s)
{
	s = clear_str(s);
	if (s == NULL)
		return (NULL);
	s = clear_semicolon(s);
	s = clear_pipe(s);
	s = clear_ampersand(s);
	s = clear_dpipe(s);
	s = clear_dampersand(s);
	s = clear_redirect_left(s);
	s = clear_redirect_right(s);
	s = clear_redirect_dleft(s);
	s = clear_redirect_dright(s);
	if (s[0] != '\0' && s[0] == '&' && s[1] != '\0'
	&& s[1] == '&' && s[2] == '\0') {
		free(s);
		return (NULL);
	}
	return (s);
}
