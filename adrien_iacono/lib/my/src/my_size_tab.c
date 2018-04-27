/*
** EPITECH PROJECT, 2017
** my_size_tab.c
** File description:
** Made by developers
*/

#include "my.h"

int		my_size_tab(char **tab)
{
	int	i = -1;

	if (tab == NULL)
		return (0);
	while (tab[++i]);
	return (i);
}
