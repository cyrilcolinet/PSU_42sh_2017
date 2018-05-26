/*
** EPITECH PROJECT, 2018
** 42
** File description:
** var
*/

#include "42.h"

int	is_a_variable_assign(char **cmd, env_t *env)
{
	if (cmd && valid_variable(cmd) == 1) {
		add_variable_in_shell(env, cmd);
		return 1;
	}
	return -1;
}

int	valid_variable(char **cmd)
{
	int valid = 0;

	if (my_strcmp(cmd[0], "set") != 0 || my_array_size(cmd) > 2)
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
	for (;cmd && cmd[j] && cmd[j] != '='; j++) {
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
