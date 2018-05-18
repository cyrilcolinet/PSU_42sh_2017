/*
** EPITECH PROJECT, 2018
** clear_redirect_dright
** File description:
** 42
*/

#include "42.h"

static char *malloc_str(char *s, int i)
{
	char *str = NULL;
	int count = 1;

	if (i > 0 && s[i - 1] != ' ')
		count++;
	if (s[i + 2] != '\0' && s[i + 2] != ' ')
		count++;
	str = malloc(sizeof(char) * (my_strlen(s) + count));
	return (str);
}

static char *fill_str(char *s, char *str, int i, int a)
{
	if (i > 0 && s[i - 1] != ' ') {
		str[a] = ' ';
		a++;
	}
	str[a] = s[i];
	a++;
	str[a] = s[i + 1];
	a++;
	if (s[i + 2] != '\0' && s[i + 2] != ' ') {
		str[a] = ' ';
		a++;
	}
	if (s[i + 2] != '\0' && s[i + 2] == ' ')
		i++;
	for (int j = i + 2; s[j] != '\0'; j++) {
		str[a] = s[j];
		a++;
	}
	str[a] = '\0';
	return (str);
}

static char *modif_str(char *s, int i)
{
	char *str = malloc_str(s, i);
	int a = 0;

	for (int j = 0; j < i; j++) {
		str[a] = s[j];
		a++;
	}
	str = fill_str(s, str, i, a);
	free(s);
	return (str);
}

static bool is_redirect_dright(char *s, int i)
{
	if (s[i] != '>' || s[i + 1] == '\0' || s[i + 1] != '>')
		return (false);
	if (i == 0 && s[i + 2] != '\0' && s[i + 2] == ' ')
		return (false);
	if (s[i + 2] == '\0' && i > 0 && s[i - 1] == ' ')
		return (false);
	if (i > 0 && s[i - 1] == ' ' && s[i + 2] != '\0'
	&& s[i + 2] == ' ')
		return (false);
	return (true);
}

char *clear_redirect_dright(char *s)
{
	int quote = 1;
	int dquote = 1;

	for (int i = 0; s[i] != '\0'; i++ ) {
		if (s[i] == 39)
			quote *= -1;
		if (s[i] == 34)
			dquote *= -1;
		if (quote != -1 && dquote != -1
		&& is_redirect_dright(s, i)) {
			s = modif_str(s, i);
		}
	}
	return (s);
}
