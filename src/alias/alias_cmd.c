/*
** EPITECH PROJECT, 2018
** 42
** File description:
** alias
*/
#include "42.h"

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
		//print aliases
		return;
	}
	name_ptr = strdup(cmd[1]);
	cmd_ptr = strdup(cmd[2]);
	for (int i = 2; cmd && cmd[i]; i++) {
		if (i != 0)
			cmd_ptr = my_strjoin_clear(cmd_ptr, " ", 0);
		cmd_ptr = my_strjoin_clear(cmd_ptr, cmd[i], 0);
	}
	printf("add alias: %s %s\n", name_ptr, cmd_ptr);
	add_shell_alias(&env->shell_alias, name_ptr, cmd_ptr);

}