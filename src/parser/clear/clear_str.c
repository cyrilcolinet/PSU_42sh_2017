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

static bool is_space(char *s, int i)
{
	if (s[i] == ' ' && s[i + 1] != ' ')
                return (false);
	return (true);
}

char *clear_str(char *s)
{
	int quote = 1;
	int dquote = 1;

	s = change_tab_space(s);
	s = clear_begin(s);
	s = clear_end(s);
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == 39)
			quote *= -1;
		if (s[i] == 34)
			dquote *= -1;
		printf("%d %d\n", quote, dquote);
		if (quote != -1 && dquote != -1
		&& s[i] == ' ' && is_space(s, i)) {
			s = clear_space(s, i);
			i--;
		}
	}
	return (s);
}
