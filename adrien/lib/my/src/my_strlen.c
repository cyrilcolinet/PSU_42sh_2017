/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** Made by developers
*/

#include "my.h"

int		my_strlen(char const *str)
{
	int	i = -1;

	if (str == NULL)
		return (0);
	while (str[++i]);
	return (i);
}
