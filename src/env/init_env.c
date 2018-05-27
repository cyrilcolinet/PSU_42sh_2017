/*
** EPITECH PROJECT, 2018
** init env
** File description:
** 42
*/

# include "shell.h"

env_t init_env(char **av_env)
{
	env_t env;

	env.str_env = av_env;
	env.listenv = init_listenv(av_env);
	env.syspath = init_syspath(env_get_variable(S_BINPATH, &env));
	env.usr_name = env_get_variable(S_USR, &env);
	env.pwd_path = env_get_variable(S_PWD, &env);
	env.bashrc_path = env_get_variable(S_HOME, &env);
	env.bashrc_path = my_strcat_malloc(env.bashrc_path, "/.bashrc");
	env.exit_code = 0;
	env.history = NULL;
	env.shell_var = NULL;
	env.shell_alias = NULL;
	return env;
}
