/*
** EPITECH PROJECT, 2018
** 42
** File description:
** pipe parser
*/

#include "42.h"

static void	add_pipe_in_list(p_pipe_t **list, char *p_cmd)
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
	char		**arr = my_str_to_array_pipe_42(cmd);
	int		i = 0;
	(void)parser;

	while (arr && arr[i]) {
		arr[i] = clear_str(arr[i]);
		add_pipe_in_list(&list_pipe, arr[i]);
		i++;
	}

	my_freetab(arr);
	return list_pipe;
}
