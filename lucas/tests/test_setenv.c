/*
** EPITECH PROJECT, 2018
** test
** File description:
** criterion
*/

#include <criterion/criterion.h>
#include "minishell.h"

Test(minishell3, test0)
{
	char *av_env[] = {"PATH=/bin/", NULL};
	char *arg[] = {"setenv", "toto", "42", NULL};
	char *arg2[] = {"setenv", "toto", "1", NULL};
	env_t env = init_env(av_env);

	my_setenv_cmd(&env, arg);
	cr_assert_str_eq(env.listenv->next->line, "toto=42");
	my_setenv_cmd(&env, arg2);
	cr_assert_str_eq(env.listenv->next->line, "toto=1");
}

Test(minishel3, test1)
{
	char *av_env[] = {"PATH=/bin/", NULL};
	char *arg[] = {"setenv", "toto", NULL};
	env_t env = init_env(av_env);

	my_setenv_cmd(&env, arg);
	cr_assert_str_eq(env.listenv->next->line, "toto=");
}

Test(minishel3, test2)
{
	char *av_env[] = {"PATH=/bin/", NULL};
	char *arg[] = {"setenv", NULL};
	env_t env = init_env(av_env);

	my_setenv_cmd(&env, arg);
}

Test(minishel3, test3)
{
	char *av_env[] = {"PATH=/bin/", NULL};
	char *arg[] = {"setenv", "", NULL};
	char *arg2[] = {"setenv", "toto=", NULL};
	env_t env = init_env(av_env);

	my_setenv_cmd(&env, arg);
	my_setenv_cmd(&env, arg2);
}
