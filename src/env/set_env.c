/*
** EPITECH PROJECT, 2018
** set_env
** File description:
** 42
*/

#include "42.h"

int posix_bug(char *name, env_t *env)
{
	int i = 0;

	if (my_strlen(name) == 0 || (name[0] >= '0' && name[0] <= '9')) {
		my_putstr("setenv: Variable name must begin");
		my_putstr(" with a letter.\n");
		env->exit_code = 1;
		return 0;
	}
	while (name && name[i]) {
		if (name[i] == '=') {
			my_putstr("setenv: Variable name must ");
			my_putstr("contain alphanumeric characters.\n");
			env->exit_code = 1;
			return 0;
		}
		i++;
	}
	return 1;
}

int change_env(env_t *env, char *name, char *value)
{
	listenv_t *tmp = env->listenv;
	char *tmp_cont = NULL;
	char *v = NULL;
	char *c = NULL;

	while (tmp->next != NULL) {
		if (my_strequ(tmp->next->var, name)) {
			tmp_cont = realloc_char(my_strdup(value),
			my_strlen(value));
			free(tmp->next->content);
			tmp->next->content = my_strdup(tmp_cont);
			free(tmp_cont);
			return (0);
		}
		tmp = tmp->next;
	}
	v = my_strdup(name);
	c = my_strdup(value);
	tmp->next = new_environment_entry(v, c, tmp->next);
	return (0);
}

int my_setenv(env_t *env, char *name, char *value, int overwrite)
{
	int error = 0;
	(void)overwrite;

	if (posix_bug(name, env) == 0)
		return -1;
	change_env(env, name, value);
	return error;
}
