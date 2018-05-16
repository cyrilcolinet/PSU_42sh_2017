/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** pipe parser
*/

#include "minishell.h"

void		add_pipe_in_list(p_pipe_t **list, char *p_cmd)
{
	p_pipe_t	*tmp = *list;
	p_pipe_t	*node = malloc(sizeof(*node));

	node->pipe_cmd = my_strcat_malloc(NULL, p_cmd);
	node->next = NULL;
	if (*list == NULL) {
		*list = node;
	} else {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

p_pipe_t	*get_pipe_in_cmd(parser_t **parser, char *cmd)
{
	p_pipe_t	*list_pipe = NULL;
	char		**tab = my_str_to_word_array(cmd, '|');
	int		i = 0;

	while (tab && tab[i]) {
		add_pipe_in_list(&list_pipe, tab[i]);
		i++;
	}
	(void)parser;
	return list_pipe;
}
