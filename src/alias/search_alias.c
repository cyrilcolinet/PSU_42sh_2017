/*
** EPITECH PROJECT, 2018
** 42
** File description:
** alias
*/
#include "42.h"

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

char	*search_alias(char *cmd, env_t *env)
{
	FILE	*fp = fopen(env->bashrc_path, "rw");
	char	*buff = NULL;
	size_t	len = 0;
	ssize_t	read = 0;
	char	*alias = NULL;

	if (fp == NULL)
		return NULL;
	while ((read = getline(&buff, &len, fp)) != -1) {
		if (my_strncmp(buff, "alias", 5) == 0)
			alias = is_cmd_alias(buff, cmd, env);
		if (alias) {
			fclose(fp);
			free(buff);
			return alias;
		}
	}
	free(buff);
	fclose(fp);
	return NULL;
}
