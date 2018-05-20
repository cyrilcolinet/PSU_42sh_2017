/*
** EPITECH PROJECT, 2018
** my_str_to_array_42
** File description:
** 42
*/

#include "42.h"

static int get_len(char *str, char delim, int i)
{
	int len = 0;
	int quote = 1;
	int dquote = 1;

	for (; str[i] != '\0'; i++) {
		if (str[i] == 34)
			dquote *= -1;
		if (str[i] == 39)
			quote *= -1;
		if (quote == 1 && dquote == 1 && str[i] == delim)
			break;
		len++;
	}
	return (len);
}

static char **get_the_array(char *str, int count, char delim)
{
	char **new = malloc(sizeof(char *) * (count + 1));
	int len = 0;
	int a = 0;
	int i = 0;
	int j = 0;

	if (new == NULL)
		return (NULL);
	while (str[i] != '\0') {
		while (str[i] == delim)
			i++;
		len = get_len(str, delim, i);
		new[a] = my_strconfigure(len + 1);
		if (new[a] == NULL)
			return (NULL);
		len += i;
		j = 0;
		while (i < len && str[i] != '\0') {
			new[a][j] = str[i];
			i++;
			j++;
		}
		a++;
	}
	new[count] = NULL;
	return (new);
}

char **my_str_to_array_42(char *str, char delim)
{
	char **tab = NULL;
	int count = 0;

	if (str == NULL)
		return (NULL);
	count = str_to_array_count_words(str, delim);
	if (count == 0)
		return (NULL);
	tab = get_the_array(str, count, delim);
	if (tab == NULL)
		return (NULL);
	return (tab);
}
