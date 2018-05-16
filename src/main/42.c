/*
** EPITECH PROJECT, 2018
** 42
** File description:
** main
*/

#include <42.h>
#include "42.h"

void exec_btree(char *line_cmd, env_t *env)
{
	parser_t	*b_tree = parser(line_cmd);

	while (b_tree) {
		if (b_tree->pipe_in_cmd == NULL) {
			apply_globbing(b_tree->full_cmd);
			exec_cmdline(b_tree->full_cmd, env);
		}
		b_tree = b_tree->next;
	}
}

int main(int ac, char **av, char **av_env)
{
	env_t env = init_env(av_env);
	char *buffer;

	(void)av;
	(void)ac;
	if (av_env == NULL)
		return 84;
	prompt(env);
	signal(SIGINT, SIG_IGN);
	while ((buffer = get_next_line(0))) {
		exec_btree(buffer, &env);
		if (my_strlen(buffer) > 0)
			free(buffer);
		prompt(env);
	}
	free_env(&env);
	return env.exit_code;
}
