/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** parser
*/

#include "minishell.h"

int		is_simple_cmd(char *cmd)
{
	int	i = 0;

	while (cmd && cmd[i]) {
		if (cmd[i] == '|')
			return -1;
		i++;
	}
	return 1;
}

void		append_cmd(parser_t **parser, char *cmd)
{
	parser_t	*node = NULL;
	parser_t	*tmp = *parser;

	if (!cmd)
		return;
	node = malloc(sizeof(parser_t));
	node->full_cmd = my_strcat_malloc(NULL, cmd);
	node->pipe_in_cmd = NULL;
	node->next = NULL;
	if (is_simple_cmd(cmd) == -1)
		node->pipe_in_cmd = get_pipe_in_cmd(parser, cmd);
	if (*parser == NULL) {
		*parser = node;
	} else {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

char		*epure_command_line(char *cmd)
{
	int	i = 0;

	while (cmd && cmd[i] == ' ')
		i++;
	return &cmd[i];
}

parser_t	*parser(char *av)
{
	char		**tab = my_str_to_word_array(av, ';');
	parser_t	*parser = NULL;

	for (int i = 0; tab && tab[i]; i++) {
		append_cmd(&parser, epure_command_line(tab[i]));
	}
	return parser;
}
