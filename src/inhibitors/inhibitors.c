/*
** EPITECH PROJECT, 2018
** 42
** File description:
** globbing
*/
#include "42.h"

static int	cmd_has_inhibitor(char *cmd)
{
	for (int i = 0; cmd && cmd[i]; i++) {
		if (cmd[i] == '\\')
			return 1;
	}
	return -1;
}

static char	*get_cmd_inhibitor(parser_t *b_tree)
{
	parser_t	*tmp = b_tree;
	char		*cmd = NULL;

	while (tmp) {
		if (cmd_has_inhibitor(tmp->full_cmd) == 1) {
			cmd = tmp->full_cmd;
		}
		tmp = tmp->next;
	}
	return cmd;
}

void	apply_inhibitors(parser_t **b_tree)
{
	char	*cmd_to_inhib = NULL;

	cmd_to_inhib = get_cmd_inhibitor(*b_tree);
	if (!cmd_to_inhib)
		return;
	if (error_inhibitor(cmd_to_inhib) == -1) {
		error_remove_inhibitor(cmd_to_inhib, b_tree);
		return;
	}
	change_cmd_inhibitors(b_tree, cmd_to_inhib);
	free(cmd_to_inhib);
}