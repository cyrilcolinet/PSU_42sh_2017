/*
** EPITECH PROJECT, 2018
** my_library
** File description:
** my_freetab function
*/

#include "minishell2.h"

void my_freetab(char **arr)
{
	int i = 0;

	if (arr == NULL)
		return;

	while (arr[i]) {
		free(arr[i]);
		i++;
	}

	free(arr);
	arr = NULL;
}
