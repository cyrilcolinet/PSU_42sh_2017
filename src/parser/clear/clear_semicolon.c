/*
** EPITECH PROJECT, 2018
** clear_semicolon
** File description:
** 42
*/

#include "42.h"

static int count_semicolon_space(char *s, int i)
{
	int count = 0;

	for (int n = i + 1; s[n] == ';' || s[n] == ' '; n++)
		count++;
	return (count);
}

static char *fill_str(char *s, char *str, int i, int a)
{
	for (int j = 0; j < i; j++) {
		str[a] = s[j];
		a++;
	}
	if (s[i - 1] != ' ') {
		str[a] = ' ';
		a++;
	}
	str[a] = s[i];
	a++;
	str[a] = ' ';
	a++;
	return (str);
}

static int count_charac(char *s, int i, int a)
{
	for (int j = 0; j < i; j++)
		a++;
	if (s[i - 1] != ' ')
		a++;
	a += 2;
	return (a);
}

static char *modif_semicolon(char *s, int i)
{
	char *str = NULL;
	int count = count_semicolon_space(s, i);
	int a = 0;
	int nb = 2;

	if (s[i - 1] != ' ')
		nb++;
	if (s[i + 1] != '\0' && s[i + 1] != ' ')
		nb++;
	str = malloc(sizeof(char) * (my_strlen(s) - count + nb));
	str = fill_str(s, str, i, a);
	a = count_charac(s, i, a);
	for (int j = i + 1 + count; s[j] != '\0'; j++) {
		str[a] = s[j];
		a++;
	}
	str[a] = '\0';
	free(s);
	return (str);
}

char *clear_semicolon(char *s)
{
	int quote = 1;
	int dquote = 1;

	s = clear_begin_semicolon(s);
	s = clear_end_semicolon(s);
	for (int i = 0; s[i] != '\0'; i++ ) {
		if (s[i] == 39)
			quote *= -1;
		if (s[i] == 34)
			dquote *= -1;
		if (quote != -1 && dquote != -1 && s[i] == ';')
			s = modif_semicolon(s, i);
	}
	return (s);
}
