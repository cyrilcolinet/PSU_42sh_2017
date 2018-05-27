/*
** EPITECH PROJECT, 2018
** list_to_array
** File description:
** util
*/

# include "shell.h"

void free_list_to_str(env_t *env)
{
	if (!env->str_env)
		return;
	my_freetab(env->str_env);
}

char **my_list_to_array(env_t *env_s)
{
	char **env = NULL;
	int count = 0, i = 0;
	char *data = NULL;
	listenv_t *tmp = env_s->listenv;

	while (tmp->next != NULL)
		tmp = tmp->next, count++;
	if (count == 0)
		return (NULL);
	env = malloc(sizeof(*env) * (count + 1));
	tmp = env_s->listenv;
	while (tmp->next) {
		data = my_strjoin_clear(my_strjoin_char(tmp->next->var, \
		'='), tmp->next->content, 0);
		env[i++] = my_strdup(data);
		free(data);
		tmp = tmp->next;
	}
	env[i] = NULL;
	return env;
}
