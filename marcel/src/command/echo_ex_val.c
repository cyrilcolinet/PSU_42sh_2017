/*
** EPITECH PROJECT, 2018
** echo_ex_val
** File description:
** mysh 2
*/

#include "minishell2.h"

static bool is_echo_ex_val(mysh_t *mysh)
{
	if (mysh->arg[0][0] == 'e' && mysh->arg[0][1] == 'c'
	&& mysh->arg[0][2] == 'h' && mysh->arg[0][3] == 'o'
	&& mysh->arg[0][4] == '\0') {
		if (mysh->arg[1][0] == '$' && mysh->arg[1][1] == '?'
		&& mysh->arg[1][2] == '\0') {
			my_put_nbr(mysh->ex_val);
			my_putchar('\n');
			return (true);
		}
		return (false);
	}
	return (false);
}

bool echo_ex_val(mysh_t *mysh)
{
	if (mysh->nb_arg == 2)
		if (is_echo_ex_val(mysh)) {
			mysh->ex_val = 0;
			return (true);
		}
	return (false);
}
