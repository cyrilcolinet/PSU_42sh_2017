/*
** EPITECH PROJECT, 2018
** 42
** File description:
** main
*/

#include "42.h"

static void free_struct_parser(parser_t *parser)
{
	parser_t *tmp = NULL;
	p_pipe_t *tmpipe = NULL;
	p_pipe_t *ppipe = NULL;

	while (parser != NULL) {
		tmp = parser;
		parser = parser->next;
		free(tmp->full_cmd);
		ppipe = tmp->pipe_in_cmd;
		while (ppipe != NULL) {
			tmpipe = ppipe;
			ppipe = ppipe->next;
			free(tmpipe->pipe_cmd);
			free(tmpipe);
		}
		free(tmp);
	}
}

void 	exec_btree(char *line_cmd, env_t *env)
{
	parser_t	*b_tree = parser(line_cmd);
	parser_t	*tmp = b_tree;

	apply_inhibitors(&b_tree);
	while (tmp) {
		if (tmp->pipe_in_cmd == NULL) {
			exec_cmdline(tmp->full_cmd, env);
		}
		tmp = tmp->next;
	}
	free_struct_parser(b_tree);
}

static void is_valid_buffer(char *buffer, env_t *env)
{
	buffer = clear_separator(buffer);

	if (error_management(buffer)) {
		exec_btree(buffer, env);
		fill_history(env, buffer);
	} else
		env->exit_code = 1;
	free(buffer);
}

int 	main_shell(char **av_env)
{
	env_t 		env = init_env(av_env);
	char 		*buffer = NULL;
	int		exit_code = 0;

	if (*av_env == NULL)
		return 84;
//	if (!can_apply_keybinding(&env))
//		return (84);
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
