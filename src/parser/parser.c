/*
** EPITECH PROJECT, 2018
** 42
** File description:
** parser
*/

#include "42.h"

static int		is_simple_cmd(char *cmd)
{
	int	i = 0;

	while (cmd && cmd[i] && cmd[i + 1]) {
		if (cmd[i] == '|' && cmd[i + 1] != '|')
			return -1;
		i++;
	}
	return 1;
}

static void		append_cmd(parser_t **parser, char *cmd)
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

parser_t	*parser(char *av)
{
	char		**tab;
	parser_t	*parser = NULL;

	tab = my_str_to_array_42(av, ';');
	for (int i = 0; tab && tab[i]; i++) {
		tab[i] = clear_str(tab[i]);
		append_cmd(&parser, tab[i]);
	}
	my_freetab(tab);	
	return parser;
}
