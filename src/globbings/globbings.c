/*
** EPITECH PROJECT, 2018
** 42
** File description:
** globbing
*/
#include <glob.h>
# include "shell.h"

static char	*get_glob_cmd(char *path)
{
	glob_t	globbuf;
	char	*new_cmd = NULL;
	int	glob_ret = 0;

	globbuf.gl_offs = 1;
	glob_ret = glob(path, 0, NULL, &globbuf);
	if (glob_ret == GLOB_NOMATCH)
		return path;
	free(path);
	for (int i = 0; i < (int)globbuf.gl_pathc; i++) {
		new_cmd = my_strcat_malloc(new_cmd, globbuf.gl_pathv[i]);
		if (i + 1 != (int)globbuf.gl_pathc)
			new_cmd = my_strjoin_clear(new_cmd, " ", 0);
	}
	return new_cmd;
}

char	**apply_globbing(char **cmd)
{
	char	*new_cmd = NULL;
	char	*glob = NULL;

	for (int i = 0; cmd && cmd[i]; i++) {
		if (globbing_in_cmd(cmd[i]) == 1) {
			new_cmd = my_strcat_malloc(new_cmd,
				!(glob = get_glob_cmd(cmd[i])) ? "" : glob);
			new_cmd = my_strjoin_clear(new_cmd, " ", 0);
		} else {
			new_cmd = my_strcat_malloc(new_cmd, cmd[i]);
			new_cmd = my_strjoin_clear(new_cmd, " ", 0);
		}
	}
	return my_strtok(new_cmd, ' ');
}
