/*
** EPITECH PROJECT, 2018
** clear_separator
** File description:
** 42
*/

#include "42.h"

char *clear_separator(char *s)
{
	s = clear_str(s);
	for (int i = 0; s[i] != '\0'; i++)
		printf("=%c=", s[i]);
	printf("\n");
	s = clear_semicolon(s);
	s = clear_pipe(s);
	s = clear_ampersand(s);
	s = clear_dpipe(s);
	s = clear_dampersand(s);
	s = clear_redirect_left(s);
	s = clear_redirect_right(s);
	s = clear_redirect_dleft(s);
	s = clear_redirect_dright(s);

	return (s);
}
