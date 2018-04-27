/*
** EPITECH PROJECT, 2017
** my_basicfct.c
** File description:
** Made by developers
*/

#include "minishell.h"

int		my_strstr(char *s1, char *s2)
{
	int	i = 0;

	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char		*my_strcat(char const *dest, char const *src, int c)
{
	int	i = 0;
	int	j = 0;
	char	*str3;

	str3 = malloc(sizeof(char*) * (my_strlen(dest) + my_strlen(src) + 1));
	while (dest[i] != 0) {
		str3[i] = dest[i];
		i++;
	}
	if (c)
		str3[i++] = '/';
	while (src[j])
		str3[i++] = src[j++];
	str3[i] = 0;
	return (str3);
}

int		my_str_start(char const *a, char const *b)
{
	int	i = -1;
	int	j = 0;

	while (b[++i]) {
		if (i >= my_strlen(a) || a[j++] != b[i])
			return (0);
	}
	return (1);
}

int		my_str_equals(char const *a, char const *b)
{
	int	i = -1;
	int	j = 0;

	while (b[++i]) {
		if (i >= my_strlen(a) || a[j++] != b[i])
			return (0);
	}
	if (i < my_strlen(a))
		return (0);
	return (1);
}

int		my_str_alpha(char const *str)
{
	int	i = -1;

	while (str[++i]) {
		if (!(str[i] >= 'a' && str[i] <= 'z')
			&& !(str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
	}
	return (1);
}
