/*
** EPITECH PROJECT, 2018
** count_words
** File description:
** 42
*/

#include "42.h"

static int pass_quote(char *str, int i, char delim)
{
	i++;
	while (str[i] != delim)
		i++;
	return (i);
}

int str_to_array_count_words(char *str, char delim)
{
	int count = 1;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == 39) {
			i = pass_quote(str, i, 39);
			continue;
		}
		if (str[i] == 34) {
			i = pass_quote(str, i, 34);
			continue;
		}
		if (str[i] == delim)
			count++;
	}
	return (count);
}
