/*
** EPITECH PROJECT, 2018
** test
** File description:
** criterion
*/

#include <criterion/criterion.h>
# include "shell.h"

Test(minishell, test0, .exit_code = 0)
{
	char *av_env[] = {"PWD=", "OLDPWD=", "USER=", "PATH=/bin/", NULL};
	char *arg[] = {"cd", "..  ", NULL};
	env_t env = init_env(av_env);

	my_cd(&env, arg);
}

Test(minishell, test1, .exit_code = 0)
{
	char *av_env[] = {"PWD=", "OLDPWD=", "USER=", "PATH=/bin/", NULL};
	char *arg[] = {"cd", NULL};
	env_t env = init_env(av_env);

	my_cd(&env, arg);
}

Test(minishell, test2, .exit_code = 0)
{
	char *av_env[] = {"PWD=", "OLDPWD=", "USER=", "PATH=/bin/", NULL};
	char *arg[] = {"cd", "~", NULL};
	env_t env = init_env(av_env);

	my_cd(&env, arg);
}

Test(minishell, test3, .exit_code = 0)
{
	char *av_env[] = {"PWD=", "OLDPWD=", "USER=", "PATH=/bin/", NULL};
	char *arg[] = {"cd", "-", NULL};
	env_t env = init_env(av_env);

	my_cd(&env, arg);
}

Test(minishell, test4)
{
	char *av_env[] = {"PWD=", "OLDPWD=", "USER=", "PATH=/bin/", NULL};
	char *arg[] = {"   cd ", "Makefile", NULL};
	env_t env = init_env(av_env);
	int ret = 0;

	my_cd(&env, arg);
	cr_assert_eq(ret, -1);
}
