/*
** EPITECH PROJECT, 2018
** check_env
** File description:
** minishell2
*/

#include "minishell2.h"

void check_env(mysh_t *mysh)
{
	print_env(mysh);
	mysh->overwrite = 1;
	call_unsetenv(mysh);
	call_setenv(mysh);
}
