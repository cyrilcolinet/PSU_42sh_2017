/*
** EPITECH PROJECT, 2017
** get_next_line.c
** File description:
** Made by developers
*/

#include "get_next_line.h"

int		my_strlen_gnl(char *str)
{
	int	i = 0;

	while (str && str[i])
		i++;
	return i;
}

void check_malloc_gnl(char *src)
{
	if (src == NULL)
		exit(84);
}

char *my_strcat_malloc_gnl(char *dest, char *src)
{
	int len = my_strlen_gnl(dest);
	int i = 0;
	char *res = malloc(sizeof(char) * (len + my_strlen_gnl(src) + 1));

	check_malloc_gnl(res);
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

char		*get_next_line(int fd)
{
	char	buff[1];
	char	*res = NULL;
	int	size;

	while ((size = read(fd, buff, 1)) != 0) {
		buff[size] = '\0';
		if (buff[0] == '\n') {
			if (my_strlen_gnl(res) > 0) {
				return res;
			} else {
				return "";
			}
		}
		res = my_strcat_malloc_gnl(res, buff);
	}
	return NULL;
}
