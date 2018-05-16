/*
** EPITECH PROJECT, 2018
** test
** File description:
** criterion
*/

#include <criterion/criterion.h>
#include "minishell.h"

Test(minishell4, test0)
{
	char *av_env[] = {"PATH=/bin/", "toto=42", NULL};
	char *arg[] = {"unsetenv", "toto", NULL};
	env_t env = init_env(av_env);

	my_unsetenv_cmd(&env, arg);
	if (env.listenv->next != NULL)
		cr_assert_fail();
}

Test(minishel4, test2)
{
	char *av_env[] = {"PATH=/bin/", NULL};
	char *arg[] = {"unsetenv", "PATH", NULL};
	env_t env = init_env(av_env);

	my_setenv_cmd(&env, arg);
}

Test(minishel4, test3)
{
	char *av_env[] = {"PATH=/bin/", NULL};
	char *arg[] = {"unsetenv", "PWD", NULL};
	env_t env = init_env(av_env);

	my_setenv_cmd(&env, arg);
}
