/*
** EPITECH PROJECT, 2018
** exit
** File description:
** minishell2
*/

#include "minishell2.h"

int check_exit(mysh_t *mysh)
{
	char *ex = "exit";
	int nbr = 0;
	int value = 1;

	for (int i = 0; mysh->arg[0][i] != '\0'; i++) {
		if (mysh->arg[0][i] == ex[i])
			nbr++;
	}
	if (nbr == my_strlen(ex) &&
	my_strlen(mysh->arg[0]) == my_strlen(ex))
		value = exit_fonction(mysh);
	return (value);
}
