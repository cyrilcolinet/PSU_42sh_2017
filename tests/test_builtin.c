/*
** EPITECH PROJECT, 2018
** test
** File description:
** criterion
*/

#include <criterion/criterion.h>
#include "minishell.h"

Test(minishell, test0, .exit_code = 0)
{
	char *av_env[] = {"PWD=", "OLDPWD=", "USER=", "PATH=/bin/", NULL};
	char *arg[] = {"cd", "..  ", NULL};
	env_t env = init_env(av_env);

	my_cd(arg, &env);
}

Test(minishell, test1, .exit_code = 0)
{
	char *av_env[] = {"PWD=", "OLDPWD=", "USER=", "PATH=/bin/", NULL};
	char *arg[] = {"cd", NULL};
	env_t env = init_env(av_env);

	my_cd(arg, &env);
}

Test(minishell, test2, .exit_code = 0)
{
	char *av_env[] = {"PWD=", "OLDPWD=", "USER=", "PATH=/bin/", NULL};
	char *arg[] = {"cd", "~", NULL};
	env_t env = init_env(av_env);

	my_cd(arg, &env);
}

Test(minishell, test3, .exit_code = 0)
{
	char *av_env[] = {"PWD=", "OLDPWD=", "USER=", "PATH=/bin/", NULL};
	char *arg[] = {"cd", "-", NULL};
	env_t env = init_env(av_env);

	my_cd(arg, &env);
}

Test(minishell, test4)
{
	char *av_env[] = {"PWD=", "OLDPWD=", "USER=", "PATH=/bin/", NULL};
	char *arg[] = {"   cd ", "Makefile", NULL};
	env_t env = init_env(av_env);
	int ret = 0;

	ret = my_cd(arg, &env);
	cr_assert_eq(ret, -1);
}
