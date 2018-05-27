/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** delete variable functions
*/

# include "shell.h"

void	free_shell_variables(env_t *env)
{
	shell_var_t	*tmp = env->shell_var;
	shell_var_t	*stock = NULL;

	while (tmp) {
		free(tmp->var_name);
		free(tmp->var_value);
		stock = tmp;
		tmp = tmp->next;
		free(stock);
	}
}

void	del_variable(shell_var_t **list, char *value)
{
	shell_var_t	*tmp = *list;
	shell_var_t	*prev = NULL;

	if (tmp != NULL && my_strcmp(tmp->var_name, value) == 0) {
		(*list) = tmp->next;
		free(tmp->var_name);
		free(tmp->var_value);
		free(tmp);
		return;
	}
	while (tmp && my_strcmp(tmp->var_name, value) != 0) {
		prev = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
		return;
	prev->next = tmp->next;
	free(tmp->var_name);
	free(tmp->var_value);
	free(tmp);
}

void 	del_variable_in_shell(env_t *env, char **cmd)
{
	char		*var = find_variable(env, cmd[1]);

	if (var) {
		del_variable(&env->shell_var, var);
	}
}