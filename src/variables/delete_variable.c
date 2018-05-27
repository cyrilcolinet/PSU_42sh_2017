/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** delete variable functions
*/

# include "shell.h"

void 	del_variable_in_shell(env_t *env, char **cmd)
{
	shell_var_t *tmp = env->shell_var;
	char *var = find_variable(env, cmd[1]);

	while (var && tmp != NULL) {
		if (my_strequ(tmp->var_name, cmd[1])) {
			// TODO: Delete this node and raccord prev and next
			return;
		}
		tmp = tmp->next;
	}
}
