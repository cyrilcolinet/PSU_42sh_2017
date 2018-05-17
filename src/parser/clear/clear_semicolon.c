/*
** EPITECH PROJECT, 2018
** clear_semicolon
** File description:
** 42
*/

#include "42.h"

static char *modif_semicolon(char *s, int i)
{
	return (s);
}

char *clear_semicolon(char *s)
{
	int quote = 1;
	int dquote = 1;

	s = clear_begin_semicolon(s);
	s = clear_end_semicolon(s);
	/* for (int i = 0; s[i] != '\0'; i++ ) { */
	/* 	if (s[i] == 39) */
	/* 		quote *= -1; */
	/* 	if (s[i] == 34) */
	/* 		dquote *= -1; */
	/* 	if (quote != -1 && dquote != -1 && s[i] == ';') { */
	/* 		s = modif_semicolon(s, i); */
	/* 		i = 0; */
	/* 	} */
	/* } */
	return (s);
}
