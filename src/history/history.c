/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** history_manager
*/

# include "shell.h"

static void fill_values(hist_t *node, char *cmd)
{
	node->cmd = my_strdup(cmd);
	node->next = NULL;
}

static int add_command(env_t *env, char *cmd)
{
	hist_t **hist = &env->history;
	hist_t *node = NULL;

	if (env->history == NULL) {
		node = malloc(sizeof(hist_t));
		if (node == NULL)
			return (-1);
		fill_values(node, cmd);
		node->next = *hist;
		*hist = node;
		return (0);
	}
	node = env->history;
	while (node->next != NULL)
		node = node->next;
	node->next = malloc(sizeof(hist_t));
	if (node->next == NULL)
		return (-1);
	fill_values(node->next, cmd);
	return (0);
}

void free_history(env_t *env)
{
	hist_t *tmp = NULL;

	while (env->history != NULL) {
		tmp = env->history;
		env->history = tmp->next;
		free(tmp->cmd);
		free(tmp);
	}
}

void fill_history(env_t *env, char *buffer)
{
	int res = 0;
	int fd = open(".42sh_history", O_CREAT | O_APPEND | O_RDWR, 0644);

	if (buffer == NULL || fd < 0)
		return;

	res = add_command(env, buffer);
	if (res < 0)
		write(2, "Error ocurred in fill_history.\n", 31);
	write(fd, buffer, my_strlen(buffer));
	write(fd, "\n", 1);
	close(fd);
}
