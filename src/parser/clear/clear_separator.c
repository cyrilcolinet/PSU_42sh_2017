/*
** EPITECH PROJECT, 2018
** clear_separator
** File description:
** 42
*/

#include "42.h"

char *clear_separator(char *s)
{
	s = clear_semicolon(s);
	s = clear_redirection(s);
	s = clear_pipe(s);
	s = clear_or_and(s);

	return (s);
}
