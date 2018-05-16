/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** Made by developers
*/

#include "minishell.h"

int		my_size_word(char const *str, int i, char c)
{
	int	a = 0;

	while (str[i] && str[i] != c) {
		i += 1;
		a += 1;
	}
	return (a + 1);
}

int		my_count_words(char const *str, char c)
{
	int	i = -1;
	int	a = 0;

	while (str[++i])
		if (str[i] != c && (!str[i + 1] || str[i + 1] == c))
			a += 1;
	return (a + 1);
}

char		**my_str_to_word_array(char *str, char c)
{
	char	**src;
	int	i = -1;
	int	a = -1;
	int	p = -1;

	str = my_remove_tabs(str);
	src = malloc(sizeof(char*) * my_count_words(str, c));
	while (str[++i]) {
		if (str[i] != c && (i == 0 || str[i - 1] == c) && p != -1)
			src[a][p] = 0;
		if (str[i] != c && (i == 0 || str[i - 1] == c)) {
			src[++a] = malloc(my_size_word(str, i, c));
			p = 0;
		}
		if (str[i] != c)
			src[a][p++] = str[i];
	}
	if (p != -1)
		src[a][p] = 0;
	src[a + 1] = 0;
	return (src);
}
