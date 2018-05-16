/*
** EPITECH PROJECT, 2018
** exit2
** File description:
** minishell2
*/

#include "minishell2.h"

static int check_arg(char **str)
{
	int err = 0;

	if (str[1][0] == '-') {
		for (int i = 1; str[1][i] != '\0'; i++) {
			if (str[1][i] < '0' || str[1][i] > '9') {
				err = -1;
				return (err);
			}
		}
	} else if (str[1][0] >= '0' && str[1][0] <= '9') {
		for (int i = 0; str[1][i] != '\0'; i++) {
			if (str[1][i] < '0' || str[1][i] > '9') {
				err = -1;
				return (err);
			}
		}
	}
	return (err);
}

int exit_fonction(mysh_t *mysh)
{
	int nb = 1;
	int err;

	if (mysh->nb_arg == 1) {
		return (-1);
	} else if (mysh->nb_arg > 2) {
		my_putstr("exit: Expression Syntax.\n");
		mysh->next = -1;
		mysh->ex_val = 1;
		return (1);
	}
	err = check_arg(mysh->arg);
	if (err == -1) {
		my_putstr("exit: Expression Syntax.\n");
		mysh->next = -1;
		mysh->ex_val = 1;
		return (1);
	}
	mysh->ex_val = my_getnbr(mysh->arg[1]);
	return (-1);
}
