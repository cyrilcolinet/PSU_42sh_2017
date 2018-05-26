/*
** EPITECH PROJECT, 2018
** clear_begin_end_semicolon
** File description:
** 42
*/

#include "42.h"

static char *clear_end_semicolon_space(char *s, int nb)
{
	int len = 0;
	char *str;

	len = my_strlen(s) - nb;
	str = malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++)
		str[i] = s[i];
	str[len] = '\0';
	return (str);
}

static int is_the_end(char *s, int offset)
{
	int nb = 0;

	while (s[offset] == ' ' || s[offset] == ';') {
		nb++;
		offset++;
	}
	if (s[offset] == '\0')
		return (nb);
	return (-1);
}

char *clear_end_semicolon(char *s)
{
	int nb = 0;
	char *str = NULL;

	if (s == NULL)
		return (NULL);
	for (int i = nb; s[i] != '\0'; i++) {
		if ((s[i] == ' ' || s[i] == ';')
		&& (nb = is_the_end(s, i)) > 0) {
			str = clear_end_semicolon_space(s, nb);
			free(s);
			return (str);
		}
	}
	return (s);
}

char *clear_begin_semicolon(char *s)
{
	int count = 0;
	char *str;
	int i = 0;

	while ((s[count] == ' ' || s[count] == ';')
	&& s[count] != '\0') {
		count++;
	}
	str = malloc(sizeof(char) * (my_strlen(s) + 1 - count));
	for (; s[count] != '\0'; count++) {
		str[i] = s[count];
		i++;
	}
	str[i] = '\0';
	free(s);
	return (str);
}
