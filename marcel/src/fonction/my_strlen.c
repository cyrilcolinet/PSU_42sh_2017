/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** task03D03
*/

#include "minishell2.h"

int my_strlen(char *str)
{
	int nb = 0;

	if (str == NULL)
		return (0);
	for (int i = 0; str[i] != '\0'; i++) {
		nb = i + 1;
	}
	return (nb);
}
