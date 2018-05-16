/*
** EPITECH PROJECT, 2018
** clear
** File description:
** str
*/

#include "my.h"
#include <stdlib.h>

char *clear_begin(char *str, char separator)
{
	int i = 0;

	while (str && str[i]) {
		if (str[i] != separator)
			return &str[i];
		i++;
	}
}

char *clear_space(char *str, char separator)
{
	int i = 0;
	int j = 0;
	int spaced = 0;
	char *clear = malloc(sizeof(char) * my_strlen(str) + 1);

	while (str && str[i]) {
		if (str[i] != separator) {
			clear[j] = str[i];
			j++;
			spaced = 0;
		} else if (spaced == 0 && str[i] == separator) {
			spaced = 1;
			clear[j] = separator;
			j++;
		}
		i++;
	}
	clear[j] = '\0';
	return clear;
}

char *clear_str(char *str, char separator)
{
	int i = 0;
	char *clear;

	while (str && str[i]) {
		if (str[i] == '\t')
			str[i] = separator;
		i++;
	}
	str = clear_begin(str, separator);
	clear = clear_space(str, separator);
	return clear;
}
