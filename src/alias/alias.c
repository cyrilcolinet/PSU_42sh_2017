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
	if (alias_cmd[my_strlen(alias_cmd) - 1] == 39) {
		alias_cmd[my_strlen(alias_cmd) - 1] = '\0';
		return alias_cmd;
	} else {
		free(alias_cmd);
		return NULL;
	}
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

char	*search_alias(char *cmd, env_t *env)
{
	FILE	*fp = fopen(env->bashrc_path, "rw");
	char	*buff = NULL;
	size_t	len = 0;
	ssize_t	read = 0;
	char	*alias = NULL;

	while ((read = getline(&buff, &len, fp)) != -1) {
		if (my_strncmp(buff, "alias", 5) == 0)
			alias = is_cmd_alias(buff, cmd);
		if (alias) {
			printf("alias found! -> %s\n", alias);
			fclose(fp);
			return alias;
		}
	}
	fclose(fp);
	return NULL;
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