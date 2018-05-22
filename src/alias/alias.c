/*
** EPITECH PROJECT, 2018
** 42
** File description:
** alias
*/
#include "42.h"

int	cmd_is_in_alias(char *line, char *cmd)
{
	int	i = 0;

	for (; line && line[i] && line[i] != ' '; i++);
	i++;
	if (line && my_strncmp(&line[i], cmd, my_strlen(cmd)) == 0)
		return 1;
	return -1;
}

char	*is_cmd_alias(char *line, char *cmd)
{
	char	*alias_cmd = NULL;

	line[my_strlen(line) - 1] = '\0';
	if (cmd_is_in_alias(line, cmd) == -1)
		return NULL;
	alias_cmd = get_alias_cmd(line);
	return alias_cmd;
}

char	**apply_alias(char **cmd, env_t *env)
{
	char	*alias = NULL;
	char	*new_cmd = NULL;

	for (int i = 0; cmd && cmd[i]; i++) {
		if (i == 0) {
			alias = search_alias(cmd[0], env);
			new_cmd = my_strcat_malloc(new_cmd,
				(alias) ? alias : cmd[0]);
			new_cmd = my_strjoin_clear(new_cmd, " ", 0);
		} else {
			new_cmd = my_strcat_malloc(new_cmd, cmd[i]);
			new_cmd = my_strjoin_clear(new_cmd, " ", 0);
		}
	}
	free(alias);
	//TODO free cmd array ?
	return my_strtok(new_cmd, ' ');
}