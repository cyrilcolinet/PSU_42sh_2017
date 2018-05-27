/*
** EPITECH PROJECT, 2018
** 42
** File description:
** var
*/

# include "shell.h"

int	is_a_variable_assign(char **cmd, env_t *env)
{
	if (cmd && valid_variable(cmd) && my_strequ(cmd[0], "set")) {
		add_variable_in_shell(env, cmd);
		return 1;
	} else if (cmd && my_strequ(cmd[0], "unset")) {
		if (cmd[1] == NULL) {
			my_putstr_err("unset: Too few arguments.\n");
			return 1;
		}
		if (find_variable(env, cmd[1]) != NULL)
			del_variable_in_shell(env, cmd);
		return (1);
	}
	return -1;
}

int	valid_variable(char **cmd)
{
	int valid = 0;

	if (my_strequ(cmd[0], "unset") ||
	my_array_size(cmd) > 2)
		return -1;
	if (cmd[1] && cmd[1][my_strlen(cmd[1]) - 1] == '=')
		return -1;
	for (int i = 0; cmd[1] && cmd[1][i]; i++) {
		if (cmd[1][i] == '=' && i == 0)
			return -1;
		if (cmd[1][i] == '=')
			valid++;
	}
	return (valid == 1) ? 1 : -1;
}

char	*get_variable_name(char *cmd)
{
	int	i = 0;
	int	j = 0;
	char	*name = NULL;

	while (cmd && cmd[i] && cmd[i] != '=')
		i++;
	name = malloc(sizeof(char) * (i + 1));
	for (; cmd && cmd[j] && cmd[j] != '='; j++) {
		name[j] = cmd[j];
	}
	name[j] = '\0';
	return name;
}

char	*get_variable_value(char *cmd)
{
	int	i = 0;

	if (cmd && cmd[i])
		i++;
	while (cmd && cmd[i] && cmd[i - 1] != '=')
		i++;
	return strdup(&cmd[i]);
}
