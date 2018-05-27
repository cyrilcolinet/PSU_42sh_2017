/*
** EPITECH PROJECT, 2018
** clear_space
** File description:
** 42
*/

# include "shell.h"

char *clear_space(char *s, int i)
{
	char *str;
	int offset = 0;
	int len = my_strlen(s);

	str = malloc(sizeof(char) * (len));
	for (int j = 0; s[j] != '\0'; j++) {
		if (j != i) {
			str[offset] = s[j];
			offset++;
		}
	}
	str[len - 1] = '\0';
	free(s);
	return (str);
}
