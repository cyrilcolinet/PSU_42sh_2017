/*
** EPITECH PROJECT, 2017
** get_next_line.c
** File description:
** Made by developers
*/

#include "my.h"

char		*my_strconcat(char *a, char *b)
{
	char	*res = malloc(my_strlen(a) + my_strlen(b) + 1);
	int	i = -1;
	int	j = 0;

	if (a != NULL)
		while (a[++i])
			res[j++] = a[i];
	i = -1;
	if (b != NULL)
		while (b[++i])
			res[j++] = b[i];
	res[j] = 0;
	free(a);
	return (res);
}

char		*get_next_line(int fd)
{
	char		buff[1];
	char		*res = NULL;
	int		size;

	while ((size = read(fd, buff, 1)) != 0) {
		buff[size] = 0;
		if (buff[0] == '\n' && my_strlen(res) > 0)
			break;
		res = my_strconcat(res, buff);
	}
	return (res);
}
