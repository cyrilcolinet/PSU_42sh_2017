/*
** EPITECH PROJECT, 2018
** my_str_to_array_42
** File description:
** 42
*/

#include "42.h"

static char *get_the_str(char *str, int i, char delim, int len)
{
	char *new = my_strconfigure(len + 1);
	int a = 0;

	if (new == NULL)
		return (NULL);
	while (str[i] == delim)
		i++;
	while (str[i] != delim && str[i] != '\0') {
		new[a] = str[i];
		a++;
		i++;
	}
	return (new);
}

static int get_len(char *str, char delim, int i)
{
	int len = 0;

	for (; str[i] != '\0' || str[i] != delim; i++) {
	}
	return (len);
}

static char **get_the_array(char *str, int count, char delim)
{
	char **new = malloc(sizeof(char *) * (count + 1));
	int len = 0;
	int j = 0;

	if (new == NULL)
		return (NULL);
	for (int i = 0; i < count; i++) {
		len = get_len(str, delim, j);
		new[i] = get_the_str(str, j, delim, len);
		j += len;
		if (new[i] == NULL)
			return (NULL);
		printf("NEW %d  =%s=\n", i, new[i]);
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
	tab = get_the_array(str, count, delim);
	if (tab == NULL)
		return (NULL);
	return (tab);
}
