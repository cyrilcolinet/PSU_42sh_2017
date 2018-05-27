/*
** EPITECH PROJECT, 2018
** syspath
** File description:
** 42
*/

# include "shell.h"

static void add_syspath(syspath_t **list, char *n_path)
{
	syspath_t *node = malloc(sizeof(*node));

	if (!node)
		exit(84);
	node->path = NULL;
	node->path = my_strcat_malloc(node->path, n_path);
	node->next = *list;
	*list = node;
}

static void fill_list(syspath_t **list, char *buffer, char *syspath)
{
	int i = 0;
	int k = 0;

	while (is_alone(syspath) != 0 && syspath && syspath[i]) {
		if (syspath[i] == ':') {
			buffer[k] = '\0';
			add_syspath(list, buffer);
			k = 0;
			i++;
		} else {
			buffer[k] = syspath[i];
			k++;
			i++;
		}
	}
}

syspath_t *init_syspath(char *syspath)
{
	syspath_t *list = NULL;
	char buffer[1024];

	if (syspath == NULL)
		return NULL;
	else if (is_alone(syspath) == 0)
		add_syspath(&list, syspath);
	fill_list(&list, buffer, syspath);
	return list;
}

static void free_pathname(env_t *env)
{
	syspath_t *tmp = env->syspath;

	while (tmp) {
		if (tmp->path)
			free(tmp->path);
		tmp = tmp->next;
	}
}

void free_syspath(env_t *env)
{
	syspath_t *tmp = env->syspath;

	free_pathname(env);
	while (tmp) {
		env->syspath = tmp;
		tmp = env->syspath->next;
		free(env->syspath);
	}
}
