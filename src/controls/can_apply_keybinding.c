/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** can_apply_keybinding functions
*/

# include "42.h"

bool can_apply_keybinding(env_t *env)
{
	if (!load_keys(env)) {
		write(2, "Error during binding creation.\n", 31);
		return (false);
	}

	return (true);
}
