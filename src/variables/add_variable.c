/*
** EPITECH PROJECT, 2018
** 42
** File description:
** globbing
*/
#include "42.h"

void	push_var_in_shell(shell_var_t **shell_var, char *name, char *value)
{
	shell_var_t	*node = NULL;

	node = malloc(sizeof(*node));
	node->var_name = name;
	node->var_value = value;
	node->next = *shell_var;
	*shell_var = node;
}

void	add_variable_in_shell(env_t *env, char *cmd)
{
	char	*name = NULL;
	char	*value = NULL;

	if (valid_variable(cmd) == -1)
		return;
	name = get_variable_name(cmd);
	value = get_variable_value(cmd);
	push_var_in_shell(&env->shell_var, name, value);
}