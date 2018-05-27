/*
** EPITECH PROJECT, 2018
** 42
** File description:
** echo
*/
# include "shell.h"

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

void	echo_variable(env_t *env, char *type)
{
	char *local_var = NULL;

	if (my_strlen(type) <= 1)
		return;
	if (my_strcmp(type, "$?") == 0)
		my_put_nbr(env->exit_code);
	else {
		local_var = find_variable(env, &type[1]);
		if (local_var == NULL) {
			my_putstr_err(&type[1]);
			my_putstr(": Undefined variable.");
		} else {
			my_putstr(local_var);
			env->exit_code = 0;
		}
	}
}

void	my_echo(env_t *env, char **cmd)
{
	if (my_array_size(cmd) > 1 && cmd[1][0] == '$') {
		echo_variable(env, cmd[1]);
		my_putstr("\n");
	}  else if (my_array_size(cmd) > 1) {
		basic_echo(cmd[1]);
		env->exit_code = 0;
	} else {
		my_putstr("\n");
		env->exit_code = 0;
	}
}
