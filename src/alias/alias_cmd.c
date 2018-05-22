/*
** EPITECH PROJECT, 2018
** 42
** File description:
** alias
*/
#include "42.h"

char	*search_shell_alias(env_t *env, char *cmd)
{
	shell_alias_t	*tmp = env->shell_alias;

	while (tmp) {
		if (my_strcmp(tmp->alias_name, cmd) == 0)
			return tmp->alias_cmd;
		tmp = tmp->next;
	}
	return NULL;
}

void	add_shell_alias(shell_alias_t **list, char *name, char *cmd)
{
	shell_alias_t	*alias;

	alias = malloc(sizeof(*alias));
	if (!alias)
		return;
	alias->alias_name = name;
	alias->alias_cmd = cmd;
	alias->next = *list;
	*list = alias;
}

void	my_alias(env_t *env, char **cmd)
{
	char	*name_ptr = NULL;
	char	*cmd_ptr = NULL;

	if (my_array_size(cmd) < 3) {
		if (my_array_size(cmd) == 1)
			print_alias(env);
		return;
	}
	name_ptr = strdup(cmd[1]);
	cmd_ptr = strdup(cmd[2]);
	for (int i = 3; cmd[i]; i++) {
		if (i != 0)
			cmd_ptr = my_strjoin_clear(cmd_ptr, " ", 0);
		cmd_ptr = my_strjoin_clear(cmd_ptr, cmd[i], 0);
	}
	add_shell_alias(&env->shell_alias, name_ptr, cmd_ptr);

}