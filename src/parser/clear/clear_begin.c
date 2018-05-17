/*
** EPITECH PROJECT, 2018
** clear_begin
** File description:
** 42
*/

# include "42.h"

char *clear_begin(char *s)
{
	char *str;
	int nb = 0;
	int offset = 0;

	if (s == NULL)
		return (NULL);
	if (s[0] == ' ')
		for (int i = 0; s[i] == ' '; i++)
			nb++;
	str = my_strconfigure(my_strlen(s) - nb);
	for (int i = nb; s[i] != '\0'; i++) {
		str[offset] = s[i];
		offset++;
	}
	free(s);
	return (str);
}
