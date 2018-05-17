/*
** EPITECH PROJECT, 2018
** clear_end
** File description:
** 42
*/

#include "42.h"

static char *clear_end_space(char *s, int nb)
{
	int len = 0;
	char *str;

	len = my_strlen(s) - nb;
	str = malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++)
		str[i] = s[i];
	str[len] = '\0';
	free(s);
	return (str);
}

static int is_the_end(char *s, int offset)
{
	int nb = 0;

	while (s[offset] == ' ') {
		nb++;
		offset++;
	}
	if (s[offset] == '\0')
		return (nb);
	return (-1);
}

char *clear_end(char *s)
{
	int nb = 0;

	if (s == NULL)
		return (NULL);
	for (int i = nb; s[i] != '\0'; i++) {
		if (s[i] == ' ' && (nb = is_the_end(s, i)) > 0) {
			s = clear_end_space(s, nb);
			return (s);
		}
	}
	return (s);
}
