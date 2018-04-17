/*
** EPITECH PROJECT, 2018
** main
** File description:
** 42 bootstrap
*/

#include "bootstrap.h"

int bootstrap(char **av)
{
	return (0);
}

int main(int ac, char **av, char **env)
{
	int res = 84;

	if (*env == NULL)
		return (84);

	if (ac != 4) {
		write(1, "Wrong arguments number.\n", 24);
		return (84);
	}

	res =bootstrap(av);
	return (res);
}
