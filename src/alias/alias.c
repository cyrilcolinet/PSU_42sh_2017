/*
** EPITECH PROJECT, 2018
** 42
** File description:
** alias
*/

# include "shell.h"

void	print_alias(env_t *env)
{
	shell_alias_t	*tmp = env->shell_alias;

	while (tmp) {
		printf("%s\t%s\n", tmp->alias_name, tmp->alias_cmd);
		tmp = tmp->next;
	}
}

int	cmd_is_in_alias(char *line, char *cmd)
{
	int	i = 0;

	for (; line && line[i] && line[i] != ' '; i++);
	i++;
	if (line && my_strncmp(&line[i], cmd, my_strlen(cmd)) == 0)
		return 1;
	return -1;
}

char	*is_cmd_alias(char *line, char *cmd, env_t *env)
{
	char	*alias_cmd = NULL;

	if ((alias_cmd = search_shell_alias(env, cmd)))
		return alias_cmd;
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
	char	**tmp = NULL;

	for (int i = 0; cmd && cmd[i]; i++) {
		if (i == 0) {
			alias = search_alias(cmd[0], env);
			new_cmd = my_strjoin("",
				(alias) ? alias : cmd[0]);
		} else {
			new_cmd = my_strjoin_clear(new_cmd, " ", 0);
			new_cmd = my_strjoin_clear(new_cmd, cmd[i], 0);
		}
	}
	my_freetab(cmd);
	tmp = my_str_to_array_42(new_cmd, ' ');
	free(new_cmd);
	return (tmp);
}
