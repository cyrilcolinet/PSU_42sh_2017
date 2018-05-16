/*
** EPITECH PROJECT, 2018
** test
** File description:
** criterion
*/

#include <criterion/criterion.h>
#include "42.h"

Test(prompt, test0)
{
	char *av_env[] = {"PATH=/bin/:usr/bin/", "PWD=/home/lucasg", NULL};
	env_t env = init_env(av_env);
	char *res;

	res = get_cdir(env);
	cr_assert_str_eq(res, "lucasg");
	prompt(env);
}
