/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** Duplicate once
*/

# include "minishell2.h"

char *my_strdup(char *str)
{
	int size = my_strlen(str) + 1;
	char *new_str = my_strconfigure(size);

	for (int i = 0; str[i] != '\0'; i++)
		new_str[i] = str[i];
	return (new_str);
}
