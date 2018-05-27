/*
** EPITECH PROJECT, 2018
** unset
** File description:
** 42
*/

# include "shell.h"

static void env_del_variable(char *var, env_t *env)
{
	listenv_t *tmp = env->listenv;
	listenv_t *tmp2 = NULL;

	while (tmp->next != NULL) {
		if (my_strequ(tmp->next->var, var)) {
			free(tmp->next->var);
			free(tmp->next->content);
			tmp2 = tmp->next;
			tmp->next = tmp->next->next;
			free(tmp2);
			return;
		}
		tmp = tmp->next;
	}
}

int my_unsetenv(env_t *env, char *name)
{
	int error = 0;

	if (error == -1) {
		write(1, "unsetenv: Too few arguments.\n", 29);
		env->exit_code = 1;
		return (-1);
	}

	env_del_variable(name, env);

	return (error);
}
