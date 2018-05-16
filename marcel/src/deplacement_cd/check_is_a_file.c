/*
** EPITECH PROJECT, 2018
** check_is_a_file
** File description:
** minishell2
*/

#include "minishell2.h"

static int check_end(char *s)
{
	int count = 0;

	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == '/' && s[i + 1] != '\0')
			count++;
	}
	if (count > 0)
		return (count);
	return (0);
}

static char *get_path(char *s, int count)
{
	char *str;
	int len = 0;
	int k = 0;

	for (int i = 0;  count > 0 && s[i] != '\0'; i++) {
		if (s[i] == '/' && s[i + 1] != '\0')
			count--;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	for (int j = 0; j < len; j++) {
		str[k] = s[j];
		k++;
	}
	return (str);
}

static char *get_name(char *s, int count)
{
	char *str;
	int len = 0;
	int len2 = my_strlen(s);
	int k = 0;

	for (int i = 0;  count > 0 && s[i] != '\0'; i++) {
		if (s[i] == '/' && s[i + 1] != '\0')
			count--;
		len++;
	}
	str = malloc(sizeof(char) * (len2 - len + 1));
	str[len2 - len] = '\0';
	for (int j = len; j < len2; j++) {
		str[k] = s[j];
		k++;
	}
	return (str);
}

char **check_is_a_file(char *str, mysh_t *mysh)
{
	char **s = malloc(sizeof(char *) * 3);
	int nb = check_end(str);

	if (nb > 0) {
		s[0] = get_path(str, nb);
		s[1] = get_name(str, nb);
	} else {
		s[0] = malloc(sizeof(char) * 3);
		s[0][0] = '.';
		s[0][1] = '/';
		s[0][2] = '\0';
		s[1] = malloc(sizeof(char) * (my_strlen(str) + 1));
		for (int i = 0; str[i] != '\0'; i++)
			s[1][i] = str[i];
		s[1][my_strlen(str)] = '\0';
	}
	s[2] = NULL;
	return (s);
}
