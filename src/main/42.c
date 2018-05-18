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

	while (tmp) {
		if (tmp->pipe_in_cmd == NULL) {
			exec_cmdline(tmp->full_cmd, env);
		}
		tmp = tmp->next;
	}
	free_struct_parser(b_tree);
}

int 	main(int ac, char **av, char **av_env)
{
	env_t 		env = init_env(av_env);
	char 		*buffer = NULL;
	(void)av;
	(void)ac;

	if (av_env == NULL)
		return 84;
	prompt(env);
	signal(SIGINT, SIG_IGN);
	while ((buffer = get_next_line(0))) {
		buffer = clear_separator(buffer);
		printf("CLEAR SEPARATOR STR = =%s=\n", buffer);
		exec_btree(buffer, &env);
		fill_history(&env, buffer);
		if (my_strlen(buffer) > 0)
			free(buffer);
		prompt(env);
	}
	free_env(&env);
	return env.exit_code;
}
