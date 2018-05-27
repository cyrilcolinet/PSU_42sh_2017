/*
** EPITECH PROJECT, 2018
** 42
** File description:
** main
*/

# include "shell.h"

static void is_valid_buffer(char *buffer, env_t *env)
{
	buffer = clear_separator(buffer);
	if (buffer == NULL)
		return;
	if (error_management(buffer)) {
		fill_history(env, buffer);
		exec_btree(buffer, env);
	} else {
		env->exit_code = 1;
		free(buffer);
	}
}

int 	main_shell(char **av_env)
{
	env_t env = init_env(av_env);
	char *buffer = NULL;
	int exit_code = 0;
	char *(*gnl[])(env_t *) = { &default_gnl, &ncurses_gnl };

	// if (!ncurses_loader(&env))
	// 	return (84);
	prompt(env);
	signal(SIGINT, SIG_IGN);
	while ((buffer = gnl[isatty(0)](&env))) {
		if (my_strlen(buffer) > 0)
			is_valid_buffer(buffer, &env);
		prompt(env);
	}
	exit_code = env.exit_code;
	free_env(&env);
	return (exit_code);
}
