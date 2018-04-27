/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** Made by developers
*/

#include "my.h"

char		*my_strcpy(char *buffer)
{
	int	i = -1;
	char	*result = malloc(my_strlen(buffer) + 1);

	while (buffer[++i])
		result[i] = buffer[i];
	result[i] = 0;
	return (result);
}
