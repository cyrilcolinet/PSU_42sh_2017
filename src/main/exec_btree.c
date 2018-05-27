/*
** EPITECH PROJECT, 2018
** exec_btree
** File description:
** 42sh
*/

#include "shell.h"

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

static void exec_line(char **line, env_t *env, parser_t *b_tree)
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

static void exec_split_line(char *str, env_t *env, parser_t* b_tree)
{
	env->line_sep = split_line_separator(str);
	for (int i = 0; env->line_sep[i] != NULL; i++) {
		env->line = str_to_tab_separator(env->line_sep[i]);
		exec_line(env->line, env, b_tree);
		my_freetab(env->line);
		if (env->exit_code == 0)
			break;
	}
	my_freetab(env->line_sep);
}

void	exec_all_pipes(parser_t *cmd, env_t *env, parser_t *b_tree)
{
	p_pipe_t *tmp = cmd->pipe_in_cmd;

	while (tmp) {
		env->pipe_next = tmp->next != NULL ? 1 : 0;
		exec_split_line(tmp->pipe_cmd, env, b_tree);
		tmp = tmp->next;
	}
}

void exec_btree(char *line_cmd, env_t *env)
{
	parser_t	*b_tree = parser(line_cmd);
	parser_t	*tmp = b_tree;

	free(line_cmd);
	apply_inhibitors(&b_tree);
	while (tmp) {
		env->pipe_fdin = 0;
		env->pipe_next = 0;
		if (tmp->pipe_in_cmd != NULL) {
			exec_all_pipes(tmp, env, b_tree);
			tmp = tmp->next;
			continue;
		}
		exec_split_line(tmp->full_cmd, env, b_tree);
		tmp = tmp->next;
	}
	free_struct_parser(b_tree);
}
