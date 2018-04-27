/*
** EPITECH PROJECT, 2017
** utils2.c
** File description:
** Made by developers
*/

#include "minishell.h"

char		*my_remove_tabs(char *str)
{
	int	i = -1;

	while (str[++i]) {
		if (str[i] == '\t')
			str[i] = ' ';
	}
	return (str);
}
