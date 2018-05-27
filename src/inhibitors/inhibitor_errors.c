/*
** EPITECH PROJECT, 2018
** 42
** File description:
** inhib
*/
# include "shell.h"

int	error_inhibitor(char *cmd)
{
	int	i = 0;

	for (; cmd && cmd[i]; i++);
	if (cmd && cmd[i - 1] == '\\')
		return 1;
	return -1;
}

void	error_remove_inhibitor(char *cmd, parser_t **b_tree)
{
	int		i = 0;
	int		j = 0;
	char		*new = malloc(sizeof(char) * my_strlen(cmd));
	parser_t	*tmp = *b_tree;

	while (cmd && cmd[i]) {
		if (cmd[i] != '\\') {
			new[j] = cmd[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	while (tmp) {
		if (my_strcmp(tmp->full_cmd, cmd) == 0)
			tmp->full_cmd = new;
		tmp = tmp->next;
	}
}