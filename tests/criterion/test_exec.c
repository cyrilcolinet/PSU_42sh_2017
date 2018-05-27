/*
** EPITECH PROJECT, 2018
** test
** File description:
** criterion
*/

#include <criterion/criterion.h>
# include "shell.h"

Test(exec, test0)
{
	char *av_env[] = {"PATH=/bin/:usr/bin/", "toto=52", NULL};
	env_t env = init_env(av_env);
	char cmd[] = "ls -l";

	exec_cmdline(cmd, &env);
}

Test(exec, test1)
{
	char *av_env[] = {"PATH=/bin/:usr/bin/", "toto=52", NULL};
	env_t env = init_env(av_env);
	char cmd[] = "env";

	exec_cmdline(cmd, &env);
}


Test(exec, test2)
{
	char *av_env[] = {"PATH=/bin/:usr/bin/", "toto=52", NULL};
	env_t env = init_env(av_env);

	exec_cmdline(NULL, &env);
}

Test(exec, test3)
{
	char *av_env[] = {"PATH=/bin/:usr/bin/", "toto=52", NULL};
	env_t env = init_env(av_env);
	char cmd[] = "./src";

	exec_cmdline(cmd, &env);
}
