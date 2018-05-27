/*
** EPITECH PROJECT, 2018
** test
** File description:
** criterion
*/

#include <criterion/criterion.h>
# include "shell.h"

Test(minishell5, test0)
{
	char *av_env[] = {"PATH=/bin/:usr/bin/", "toto=52", NULL};
	env_t env = init_env(av_env);

	cr_assert_str_eq(env.syspath->path, "/bin/");
}
