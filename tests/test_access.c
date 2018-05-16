/*
** EPITECH PROJECT, 2018
** test
** File description:
** criterion
*/

#include <criterion/criterion.h>
#include "minishell.h"

Test(minishell7, test0)
{
	char *av_env[] = {"PATH=/bin/:/usr/bin:/usr/local/sbin", "toto=42",
		NULL};
	char cmd[] = "ls";
	char inv[] = "toto";
	env_t env = init_env(av_env);
	char *res;
	int w;

	res = get_path(&env, cmd, &w);
	cr_assert_str_eq(res, "/usr/bin/ls");
	res = get_path(&env, inv, &w);
}

Test(minishell7, error)
{
	char *av_env[] = {"PATH=/bin/:/usr/bin:/usr/local/sbin", "toto=42",
		NULL};
	env_t env = init_env(av_env);
	char *res = NULL;
	int w;

	res = res;
	res = get_path(&env, NULL, &w);
	res = get_path(&env, "./a.out", &w);
	res = get_path(&env, "/bin/ls", &w);
}
