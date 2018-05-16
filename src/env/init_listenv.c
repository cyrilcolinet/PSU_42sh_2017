/*
** EPITECH PROJECT, 2018
** listenv
** File description:
** minishell
*/

#include "42.h"

void add_line(listenv_t **list, char *line)
{
	listenv_t *node = malloc(sizeof(*node));
	listenv_t *temp = *list;

	if (!node)
		exit(84);
	node->line = NULL;
	node->line = my_strcat_malloc(node->line, line);
	node->next = NULL;
	if (*list == NULL)
		*list = node;
	else {
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
	}
}

listenv_t *init_listenv(char **av_env)
{
	int i = 0;
	int nb_lines = my_array_size(av_env);
	listenv_t *list = NULL;

	while (i < nb_lines) {
		add_line(&list, av_env[i]);
		i++;
	}
	return list;
}

void free_line(env_t *env)
{
	listenv_t *tmp = env->listenv;

	while (tmp) {
		if (tmp->line)
			free(tmp->line);
		tmp = tmp->next;
	}
}

void free_listenv(env_t *env)
{
	listenv_t *tmp = env->listenv;

	free_line(env);
	while (tmp) {
		env->listenv = tmp;
		tmp = env->listenv->next;
		free(env->listenv);
	}
}
