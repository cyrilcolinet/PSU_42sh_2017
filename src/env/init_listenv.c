/*
** EPITECH PROJECT, 2018
** listenv
** File description:
** 42
*/

# include "42.h"

listenv_t *new_environment_entry(char *var, char *content, listenv_t *env)
{
	env = malloc(sizeof(env_t));

	if (env == NULL || var == NULL || content == NULL)
		return (NULL);

	env->var = var;
	env->content = content;
	env->next = NULL;
	return (env);
}

void fill_environment(listenv_t *env_s, char **env)
{
	listenv_t *tmp = env_s;
	char **arr = NULL;
	char *var = NULL;
	char *content = NULL;
	int i = -1;

	while (env[++i] != NULL) {
		while (tmp->next != NULL)
			tmp = tmp->next;

		arr = my_strtok(env[i], '=');
		var = my_strdup(arr[0]);
		content = join_next_values(arr);
		tmp->next = new_environment_entry(var, content, tmp->next);
		my_freetab(arr);
		if (tmp->next == NULL)
			return;
	}
}

listenv_t *init_listenv(char **av_env)
{
	listenv_t *env = malloc(sizeof(*env));

	if (env == NULL)
		exit(84);

	env->var = NULL;
	env->content = NULL;
	env->next = NULL;
	fill_environment(env, av_env);

	return (env);
}

void free_listenv(env_t *env)
{
	listenv_t *tmp = NULL;

	while (env->listenv != NULL) {
		tmp = env->listenv;
		env->listenv = env->listenv->next;
		free(tmp->var);
		free(tmp->content);
		free(tmp);
	}
}
