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
	env_t		env = init_env(av_env);
	char		*buffer = NULL;
	int		exit_code = 0;

	// if (!can_apply_keybinding(&env))
	// 	return (84);
	prompt(env);
	signal(SIGINT, SIG_IGN);
	while ((buffer = get_next_line(0))) {
		if (my_strlen(buffer) > 0)
			is_valid_buffer(buffer, &env);
		prompt(env);
	}
	exit_code = env.exit_code;
	free_env(&env);
	return (exit_code);
}
