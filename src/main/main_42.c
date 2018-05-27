/*
** EPITECH PROJECT, 2018
** 42
** File description:
** main
*/

# include "shell.h"

void free_struct_parser(parser_t *parser)
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

static void	exec_line(char **line, env_t *env, parser_t *b_tree)
{
	int i = 0;
	int nb = 0;

	if (line[0][0] != '\0' && line[0][0] == '&'
	&& line[0][1] != '\0' && line[0][1] == '&'
	&& line[0][2] == '\0')
		i++;
	for (int i = 0; line[i] != NULL; i++) {
		exec_cmdline(line[i], env, b_tree);
		nb = check_next_separator(line, i);
		if (nb == 1 && env->exit_code == 1)
			break;
		else if (nb == 1 && env->exit_code == 0)
			i++;
	}
}

void 	exec_btree(char *line_cmd, env_t *env)
{
	parser_t	*b_tree = parser(line_cmd);
	parser_t	*tmp = b_tree;
	char		**line;

	free(line_cmd);
	apply_inhibitors(&b_tree);
	while (tmp) {
		line = str_to_tab_separator(tmp->full_cmd);
		if (tmp->pipe_in_cmd == NULL)
			exec_line(line, env, b_tree);
		my_freetab(line);
		tmp = tmp->next;
	}
	free_struct_parser(b_tree);
}

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
	env_t 		env = init_env(av_env);
	char 		*buffer = NULL;
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
