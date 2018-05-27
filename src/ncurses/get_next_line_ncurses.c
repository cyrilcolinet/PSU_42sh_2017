/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** ncurses get_next_line
*/

# include "shell.h"

char *ncurses_gnl(env_t *env)
{
	/*char buffer[4096 + 1];
	int key[4 + 1];
	char *line = NULL;

	env->hist_enable = false;
	bzero(buffer, sizeof(char) * 4096);
	write(1, env->ncs->keymap[4], my_strlen(env->ncs->keymap[4]));
	bzero(key, sizeof(int) * 4);
	*key = -1;
	key[4] = 1;

	while (read(0, line, 10) > 0 && *line != 4) {

	}*/
	return default_gnl(env);
}
