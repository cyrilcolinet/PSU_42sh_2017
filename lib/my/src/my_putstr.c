/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** Made by developers
*/

#include "my.h"

void		my_putstr(char const *str, int channel)
{
	int	i = -1;

	while (str[++i])
		my_putchar(str[i], channel);
}
