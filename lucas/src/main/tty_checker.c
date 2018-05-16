/*
** EPITECH PROJECT, 2018
** tty
** File description:
** check minishell
*/

#include "minishell.h"

int check_tty(int fd)
{
	if (isatty(fd) == 0) {
		exit(84);
	}
}
