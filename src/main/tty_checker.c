/*
** EPITECH PROJECT, 2018
** tty
** File description:
** check 42
*/

#include "42.h"

int check_tty(int fd)
{
	if (isatty(fd) == 0) {
		exit(84);
	}
}
