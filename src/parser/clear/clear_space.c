/*
** EPITECH PROJECT, 2018
** clear_space
** File description:
** 42
*/

#include "42.h"

static int count_space(char *s, int i)
{
	while (s[i] == ' ' && s[i] != '\0')
		i++;
	return (i);
}

static int get_nbr_space(char *s)
{
	int nb = 0;

	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == ' ') {
			nb++;
			i = count_space(s, i);
		}
	}
	return (nb);
}

static int get_nbr_car(char *s)
{
	int nb = 0;

	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] != ' ') {
			nb++;
		}
	}
	return (nb);
}

char *clear_space(char *s)
{
	char *str;
	int j = 0;
	int nb = 0;

	nb = get_nbr_space(s);
	nb += get_nbr_car(s);
	str = malloc(sizeof(char) * (nb + 1));
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == ' ') {
			str[j] = s[i];
			j++;
			i = count_space(s, i);
		}
		str[j] = s[i];
		j++;
	}
	str[nb] = '\0';
	free(s);
	return (str);
}
