/*
** EPITECH PROJECT, 2018
** clear_str
** File description:
** 42
*/

#include "42.h"

static char *change_tab_space(char *s)
{
	if (s == NULL)
		return (NULL);
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == '\t')
			s[i] = ' ';
	}
	return (s);
}

char *clear_str(char *s)
{
	s = change_tab_space(s);
	s = clear_begin(s);
	s = clear_end(s);
	s = clear_space(s);
	return (s);
}
