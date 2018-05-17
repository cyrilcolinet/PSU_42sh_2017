/*
** EPITECH PROJECT, 2018
** 42
** File description:
** globbing
*/
#include <glob.h>
#include "42.h"

int	get_nbgloff(char *cmd)
{
	char	**array = my_strtok(cmd, ' ');
	int	pathc_offset = 0;

	for (int i = 0; array && array[i]; i++) {
		if (array[i][0] != FLAG_START && i != 0)
			pathc_offset++;
	}
	return pathc_offset;
}

static char	**get_patterns(char *cmd, int nbgloff)
{
	char	**array = my_strtok(cmd, ' ');
	char	**patterns = malloc(sizeof(char *) * (nbgloff + 1));
	int	offset = 0;


	if (!cmd || !array)
		return NULL;
	for (int i = 0; array[i]; i++) {
		if (array[i][0] != FLAG_START && i != 0
			&& is_globbing(array[i]) != '\0') {
			patterns[offset] = strdup(array[i]);
			offset++;
		}
	}
	patterns[offset] = NULL;
	my_freetab(array);
	return patterns;
}

static char	*get_glob_cmd(char *path)
{
	glob_t	globbuf;
	char	*new_cmd = NULL;

	globbuf.gl_offs = 1;
	glob(path, 0, NULL, &globbuf);
	free(path);
	for (int i = 0; i < globbuf.gl_pathc; i++) {
		new_cmd = my_strcat_malloc(new_cmd, globbuf.gl_pathv[i]);
		if (i + 1 != globbuf.gl_pathc)
			new_cmd = my_strjoin_clear(new_cmd, " ", 0);
	}
	return new_cmd;
}

char	**apply_globbing(char **cmd)
{
	char	*new_cmd = NULL;
	char	*glob = NULL;

	//TODO don"t exec command if get_glob_cmd
	// return NULL and print error msg
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