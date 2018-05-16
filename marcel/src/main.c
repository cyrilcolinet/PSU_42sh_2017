/*
** EPITECH PROJECT, 2018
** main
** File description:
** minishell2
*/

#include "minishell2.h"

int main(int ac, char **av, char **env)
{
	int nb;

	if (env == NULL)
		return (84);
	if (ac != 1) {
		my_putstr("Invalid agument: just ./mysh is required\n");
		return (84);
	}
	nb = minishell(ac, av, env);
	return (nb);
}
