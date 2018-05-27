/*
** EPITECH PROJECT, 2018
** clear_ampersand
** File description:
** 42
*/

# include "shell.h"

static char *malloc_str(char *s, int i)
{
	char *str = NULL;
	int count = 1;

	if (i > 0 && s[i - 1] != ' ')
		count++;
	if (s[i + 1] != '\0' && s[i + 1] != ' ')
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
	if (s[i + 1] != '\0' && s[i + 1] != ' ') {
		str[a] = ' ';
		a++;
	}
	if (s[i + 1] != '\0' && s[i + 1] == ' ')
		i++;
	for (int j = i + 1; s[j] != '\0'; j++) {
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

static bool is_ampersand(char *s, int i)
{
	if (s[i] != '&')
		return (false);
	if (i > 0 && s[i - 1] == '&')
		return (false);
	if (s[i + 1] != '\0' && s[i + 1] == '&')
		return (false);
	if ((i > 0 && s[i - 1] == ' ')
	&& (s[i + 1] != '\0' && s[i + 1] == ' '))
		return (false);
	return (true);
}

char *clear_ampersand(char *s)
{
	int quote = 1;
	int dquote = 1;

	for (int i = 0; s[i] != '\0'; i++ ) {
		if (s[i] == 39)
			quote *= -1;
		if (s[i] == 34)
			dquote *= -1;
		if (quote != -1 && dquote != -1
		&& is_ampersand(s, i)) {
			s = modif_str(s, i);
		}
	}
	return (s);
}
