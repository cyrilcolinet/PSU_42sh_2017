/*
** EPITECH PROJECT, 2018
** 42
** File description:
** globbing
*/
#include "42.h"

void	echo_backsticks(char *to_print)
{
	for (int i = 0; to_print && to_print[i]; i++) {
		if (to_print[i] != '"')
			write(1, &to_print[i], 1);
	}
}

int	is_echo_backstick(char *to_print)
{
	int	backsticks = 0;

	for (int i = 0; to_print && to_print[i]; i++) {
		if (to_print[i] == '"')
			backsticks++;
	}
	return (backsticks == 2) ? 1 : -1;
}

void	basic_echo(char *to_print)
{
	if (is_echo_backstick(to_print) == 1)
		echo_backsticks(to_print);
	else
		my_putstr(to_print);
	my_putstr("\n");
}

void	my_echo(char **cmd, env_t *env)
{
	if (my_array_size(cmd) > 1 && my_strcmp(cmd[1], "$?") == 0) {
		my_put_nbr(env->exit_code);
		my_putstr("\n");
	}  else if (my_array_size(cmd) > 1)
		basic_echo(cmd[1]);
	else
		my_putstr("\n");
}