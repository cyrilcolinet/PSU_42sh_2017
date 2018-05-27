/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** ncurses_loader functions
*/

# include "shell.h"

bool ncurses_loader(env_t *env)
{
	env->ncs = malloc(sizeof(ncurses_t));
	if (env->ncs == NULL)
		return (false);

	env->ncs->keymap = NULL;
	env->ncs->commons = malloc(sizeof(commons_t));
	if (env->ncs->commons == NULL) {
		free(env->ncs);
		return false;
	}

	return (can_apply_keybinding(env));
}
