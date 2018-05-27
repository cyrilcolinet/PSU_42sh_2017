/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** load_keys functions
*/

# include "shell.h"

bool search_keys(env_t *env)
{
	int i = 0;
	char *arr[] = { "kcuu1", "kcuf1", "kcub1", "kcud1", "civis",
		"cnorm", "u7", "el", "kend", "home", "clear", "ed", NULL };

	for (i = 0; arr[i]; i++);
	env->ncs->keymap = malloc(sizeof(char *) * (i + 2));
	if (env->ncs->keymap == NULL)
		return (false);

	for (i = 0; arr[i]; i++) {
		env->ncs->keymap[i] = tigetstr(arr[i]);
		if (env->ncs->keymap[i] == NULL)
			return (false);
	}

	env->ncs->keymap[i] = "\t";
	env->ncs->keymap[i + 1] = NULL;
	return (true);
}

bool load_keys(env_t *env)
{
	char *term = env_get_variable("TERM", env);
	char *cls_on = NULL;
	int err = 0;
	bool found_key = false;

	env->ncs->active = ((setupterm(term, 1, &err) == ERR) ? false : true);
	if (env->ncs->active) {
		cls_on = tigetstr("smkx");
		if (cls_on == NULL)
			return (false);

		my_putstr(cls_on);
		found_key = search_keys(env);
		return (found_key);
	}

	return (true);
}
