/*
** EPITECH PROJECT, 2017
** my_free_tabs.c
** File description:
** Made by developers
*/

#include "my.h"

int		my_free_tab(char **tab)
{
	int	i = -1;

	if (tab == NULL)
		return (0);
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (1);
}
