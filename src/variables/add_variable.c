/*
** EPITECH PROJECT, 2018
** 42
** File description:
** add variable
*/

# include "shell.h"

void	push_var_in_shell(shell_var_t **shell_var, char *name, char *value)
{
	shell_var_t	*node = NULL;

	node = malloc(sizeof(*node));
	node->var_name = name;
	node->var_value = value;
	node->next = *shell_var;
	*shell_var = node;
}

void	add_variable_in_shell(env_t *env, char **cmd)
{
	char	*name = NULL;
	char	*value = NULL;

	if (valid_variable(cmd) == -1)
		return;
	name = get_variable_name(cmd[1]);
	value = get_variable_value(cmd[1]);
	push_var_in_shell(&env->shell_var, name, value);
}
