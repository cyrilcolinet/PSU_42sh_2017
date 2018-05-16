/*
** EPITECH PROJECT, 2018
** test
** File description:
** criterion
*/

#include <criterion/criterion.h>
#include "minishell.h"

Test(minishell6, test0)
{
	char *av_env[] = {"PATH=/bin/", "PWD=", "OLDPWD=", "toto=42", NULL};
	char *arg[] = {"unsetenv", "toto", NULL};
	char *arg1[] = {"setenv", "toto", NULL};
	char *arg2[] = {"cd", "toto", NULL};
	char *arg3[] = {"env", NULL};
	char *arg4[] = {"exit", NULL};
	env_t env = init_env(av_env);

	call_builtins(0, arg, &env);
	call_builtins(1, arg1, &env);
	call_builtins(2, arg2, &env);
	call_builtins(3, arg3, &env);
	call_builtins(4, arg4, &env);
	call_builtins(132, arg, &env);
}

Test(minishel6, test1)
{
	char *builtin[] = {"cd", "env", "setenv"};
	char cd[] = "cd";
	char setenv[] = "setenv";
	int ret = 0;

	ret = is_builtin(cd, builtin);
	cr_assert_eq(ret, 0);
	ret = is_builtin(setenv, builtin);
	cr_assert_eq(ret, 2);
}
