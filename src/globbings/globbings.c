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

void	set_gloff(char *cmd, glob_t *globbuff)
{
	char	**array = my_strtok(cmd, ' ');
	int	append_glob = 0;
	size_t	nbgloff = (size_t)get_nbgloff(cmd);

	if (!cmd || !array)
		return;
	globbuff->gl_pathc = nbgloff;
	for (int i = 0; array[i]; i++) {
		if (array[i][0] != FLAG_START && i != 0) {
			append_glob++;
			glob(array[i], GLOB_DOOFFS, NULL, globbuff);
		}  else if (array[i][0] != FLAG_START && i != 0
			&& append_glob != 0)
			glob(array[i], GLOB_DOOFFS | GLOB_APPEND, NULL,
				globbuff);
	}
	my_freetab(array);
}

void	set_glob_cmd(char *cmd, glob_t *glob)
{
	char	**array = my_strtok(cmd, ' ');
	char	*glob_cmd = NULL;
	int	pathv_offset = 0;

	if (!cmd || !array)
		return;
	glob_cmd = strdup(array[0]);
	glob->gl_pathv = malloc(sizeof(char *) * 1);
	glob->gl_pathv[0] = glob_cmd;
	pathv_offset++;
	for (int i = 0; array[i]; i++) {
		if (array[i][0] == FLAG_START) {
			glob->gl_pathv = realloc(glob->gl_pathv,
				sizeof(char *) * 1);
			glob->gl_pathv[pathv_offset] = array[i];
			pathv_offset++;
		}

	}
	my_freetab(array);
}

glob_t	get_globbing(char *cmd)
{
	glob_t	glob;

	set_glob_cmd(cmd, &glob);
	set_gloff(cmd, &glob);
	return glob;
}