/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** task02
*/

#include "my.h"
#include <stdlib.h>

int my_strlen_protect(char *str)
{
	int i = 0;

	if (!str)
		return 0;
	while (str && str[i])
		i++;
	return i;
}

void check_malloc(char *src)
{
	if (src == NULL)
		exit(84);
}

char *my_strcat_malloc(char *dest, char *src)
{
	int len = my_strlen_protect(dest);
	int i = 0;
	char *res = malloc(sizeof(char) * (len + my_strlen_protect(src)) + 1);

	check_malloc(res);
	if (dest == NULL) {
		for (i = 0; src[i]; i++)
			res[i] = src[i];
		res[i] = '\0';
		return res;
	}
	for (i = 0; dest[i]; i++)
		res[i] = dest[i];
	for (i = 0; src[i] != '\0'; i++)
		res[len + i] = src[i];
	res[len + i] = '\0';
	return res;
}
