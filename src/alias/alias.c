/*
** EPITECH PROJECT, 2018
** 42
** File description:
** alias
*/
#include "42.h"

int	cmd_is_in_alias(char *line, char *cmd)
{
	for (int i = 0; line && line[i]; i++) {
		if (my_strncmp(&line[i], cmd, my_strlen(cmd)) == 0)
			return 1;
	}
	return -1;
}

char	*get_alias_cmd(char *line)
{
	int	i = 0;
	char	*alias_cmd = NULL;

	for (; line && line[i]; i++) {
		if (my_strncmp(&line[i], "='", 2) == 0)
			break;
	}
	i += 2;
	if (my_strlen(line) < i)
		return NULL;
	alias_cmd = strdup(&line[i]);
	if (alias_cmd[my_strlen(alias_cmd)] == 39) {
		alias_cmd[my_strlen(alias_cmd) - 1] = '\0';
		return alias_cmd;
	} else
		return NULL;
}

char	*is_cmd_alias(char *line, char *cmd)
{
	char	*alias_cmd = NULL;

	if (cmd_is_in_alias(line, cmd) == -1)
		return NULL;
	alias_cmd = get_alias_cmd(line);
	return alias_cmd;
}

char	*search_alias(char *cmd)
{
	int	fd = open("/home/lucasg/.bashrc", O_RDONLY);
	char	*buff = NULL;
	char	*alias = NULL;

	if (fd < 0)
		printf("open failed\n");
	buff = get_next_line(fd);
	while (buff) {
		printf("read %s\n", buff);
		if (my_strncmp(buff, "alias", 5) == 0)
			alias = is_cmd_alias(buff, cmd);
		if (alias) {
			close(fd);
			return alias;
		}
		free(buff);
		buff = get_next_line(fd);
	}
	close(fd);
	return NULL;
}

char	**apply_alias(char **cmd)
{
	char	*alias = NULL;

	if (!cmd)
		return NULL;
	alias = search_alias(cmd[0]);
	if (alias)
		cmd[0] = alias;
	printf("alias replaced by %s\n", cmd[0]);
	return cmd;
}