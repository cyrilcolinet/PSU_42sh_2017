/*
** EPITECH PROJECT, 2017
** my_putchar.c
** File description:
** Made by developers
*/

#include "my.h"

void		my_putchar(char c, int channel)
{
	write(channel, &c, 1);
}
