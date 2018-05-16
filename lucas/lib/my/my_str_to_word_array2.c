/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int count_word(char *str, char sep)
{
	int word = 0;
	int i = 0;
	int spaced = 0;

	while (str && str[i]) {
		if (str[i] != sep && spaced == 0) {
			word++;
			spaced = 1;
		}
		if (str[i] == sep)
			spaced = 0;
		i++;
	}
	return word;
}

void attribute_line(char *buffer, char **array, int *k, int *array_nb)
{
	buffer[*k] = '\0';
	array[*array_nb] = NULL;
	array[*array_nb] = my_strcat_malloc(array[*array_nb], buffer);
	my_memset(buffer, 100);
	*k = 0;
	*array_nb = *array_nb + 1;
}

void free_and_set(char **array, int offset, char *to_free)
{
	array[offset] = NULL;
	free(to_free);
}

char **my_str_to_word_array(char *str, char sep)
{
	char **array;
	int i = 0;
	int k = 0;
	int array_nb = 0;
	char buffer[1000];

	str =  clear_str(str, ' ');
	array = malloc(sizeof(char *) * (count_word(str, sep) + 1));
	while (str && str[i]) {
		if (str[i] != sep) {
			buffer[k] = str[i];
			k++;
			i++;
		} else
			i++;
		if ((str[i] == sep || str[i] == '\0') && buffer[0] != '\0')
			attribute_line(buffer, array, &k, &array_nb);
	}
	free_and_set(array, array_nb, str);
	return array;
}
