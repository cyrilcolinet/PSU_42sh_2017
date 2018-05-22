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
	/* parser_t	*test = b_tree; */
	/* p_pipe_t	*testpipe = NULL; */

	/* while (test) { */
	/* 	printf("LINE =%s=\n", test->full_cmd); */
	/* 	testpipe = test->pipe_in_cmd; */
	/* 	while (testpipe) { */
	/* 		printf("LINE PIPE =%s=\n", testpipe->pipe_cmd); */
	/* 		testpipe = testpipe->next; */
	/* 	} */
	/* 	test = test->next; */
	/* } */
	apply_inhibitors(&b_tree);
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
	int		exit_code = 0;
	(void)av;
	(void)ac;

	if (av_env == NULL)
		return 84;
	prompt(env);
	signal(SIGINT, SIG_IGN);
//	ctrl_catcher(NULL);
	while ((buffer = get_next_line(0))) {
		if (my_strlen(buffer) > 0) {
			buffer = clear_separator(buffer);
			/* for (int i = 0; buffer[i]; i++) */
			/* 	printf("=%c=", buffer[i]); */
			/* printf("\n"); */
			/* printf("CLEAR SEPARATOR STR = =%s=\n", buffer); */
			exec_btree(buffer, &env);
			fill_history(&env, buffer);
			free(buffer);
		}
		prompt(env);
	}
	exit_code = env.exit_code;
	free_env(&env);
	return (exit_code);
}
