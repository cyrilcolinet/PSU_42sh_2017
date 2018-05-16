/*
** EPITECH PROJECT, 2018
** unsetenv cmd
** File description:
** minishel
*/

#include "minishell.h"

void my_unsetenv_cmd(env_t *env, char **av)
{
	int nb_arg = my_array_size(av);
	int i = 1;

	if (nb_arg >= 2)
		while (av && av[i]) {
			my_unsetenv(env, av[i]);
			i++;
		}
	else
		write(2, "unsetenv: Too few arguments.\n", 29);
}
