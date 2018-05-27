/*
** EPITECH PROJECT, 2018
** test
** File description:
** criterion
*/

#include <criterion/criterion.h>
# include "shell.h"

Test(minishell1, test0, .exit_code = 0)
{
	char *arg[] = {"exit", NULL};

	exit_success(arg, NULL);
}

Test(minishell1, test1, .exit_code = 1)
{
	char *arg[] = {"exit", "1", NULL};

	exit_success(arg, NULL);
}

Test(minishell1, test2)
{
	char *arg[] = {"exit", "1", "test", NULL};

	exit_success(arg, NULL);
}
