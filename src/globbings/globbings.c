/*
** EPITECH PROJECT, 2018
** 42
** File description:
** globbing
*/

#include "42.h"

char	*get_file_in_path(char *path, char *extension, char *interval,
								char type)
{
	char	*globbing = NULL;
	DIR	*directory;
	struct dirent *dir_prop;

	directory = opendir(path);
	dir_prop = readdir(directory);
	while (dir_prop) {
		if (valid_globbing_file(dir_prop->d_name, extension,
			interval) == 1) {
			globbing = my_strcat_malloc(globbing,
				dir_prop->d_name);
			globbing = my_strjoin_clear(globbing, " ", 0);
		}
		dir_prop = readdir(directory);
	}
	closedir(directory);
	return globbing;
}

char	*perform_globbing(char *cmd, char type)
{
	char	*interval = search_interval(cmd);
	char	*extension = search_extension(cmd, type);
	char	*path = search_path(cmd, type);
	char	*globbing = NULL;

	if (path && extension)
		globbing = get_file_in_path(path, extension, interval, type);
	else if (extension) {
		globbing = get_file_in_path(CURRENT_PATH,
			extension, interval, type);
	}
	free(interval);
	free(extension);
	free(path);
	return globbing;
}

char	*apply_globbing(char *cmd)
{
	char	type;
	char	*glob_cmd = NULL;

	if (!cmd)
		return NULL;
	type = is_globbing(cmd);
	if (type) {
		glob_cmd = perform_globbing(cmd, type);
		glob_cmd = my_strjoin_clear(cmd, glob_cmd, 0);
		printf("globbings = %s\n", glob_cmd);
	}
	return (!glob_cmd) ? cmd : glob_cmd;
}