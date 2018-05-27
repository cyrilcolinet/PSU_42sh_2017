/*
** EPITECH PROJECT, 2018
** exit
** File description:
** 42
*/

# include "shell.h"

void exit_success(env_t *env, char **av, parser_t *parser)
{
	int status = 0;
	int len = my_array_size(av);

	if (len > 2) {
		my_putstr_err("exit: Expression Syntax.\n");
		return;
	}
	my_freetab(env->line_sep);
	my_freetab(env->line);
	my_freetab(av);
	free_struct_parser(parser);
	if (len == 2)
		status = my_atoi(av[1]);
	else if (len == 1) {
		status = env->exit_code;
		if (env)
			free_env(env);
	}
	exit(status);
}
