/*
** EPITECH PROJECT, 2018
** call_cd
** File description:
** minishell2
*/

#include "minishell2.h"

static int check_name(char *str, char *s)
{
	int len = my_strlen(str);
	int len2 = my_strlen(s);
	int nb = 0;

	if (len == len2) {
		for (int i = 0; str[i] != '\0'; i++)
			if (str[i] == s[i])
				nb++;
		if (nb == len)
			return (1);
	}
	return (0);
}

static void check_file(char *str, mysh_t *mysh)
{
	DIR *fd;
	struct dirent *dp;
	char **name = check_is_a_file(str, mysh);

	fd = opendir(name[0]);
	while (fd > 0 && (dp = readdir(fd)) != NULL)
		if ((check_name(name[1], dp->d_name)) == 1) {
			my_putstr(str);
			my_putstr(": Not a directory.\n");
			mysh->ex_val = 1;
			closedir(fd);
			my_freetab(name);
			return;
		}
	my_freetab(name);
	closedir(fd);
	my_putstr(str);
	my_putstr(": No such file or directory.\n");
	mysh->ex_val = 1;
}

static void check_arg_2(mysh_t *mysh)
{
	DIR *fd;

	if (mysh->nb_arg == 2) {
		fd = opendir(mysh->arg[1]);
		if (fd > 0) {
			get_new_hist(mysh);
			chdir(mysh->arg[1]);
			closedir(fd);
			return;
		}
		check_file(mysh->arg[1], mysh);
		closedir(fd);
	}
}

static void check_arg(mysh_t *mysh)
{
	mysh->ex_val = 0;
	if (mysh->nb_arg == 1) {
		if (mysh->home[0] == '\0') {
			my_putstr(": No such file or directory.\n");
			mysh->ex_val = 1;
			return;
		}
		get_new_hist(mysh);
		chdir(mysh->home);
	}
	if (check_tiret(mysh) == 0 || check_wave(mysh) == 0)
		return;
	check_arg_2(mysh);
}

void call_cd(mysh_t *mysh)
{
	int nb;
	int len = my_strlen(mysh->arg[0]);

	if (len == 2) {
		if (mysh->arg[0][0] == 'c' && mysh->arg[0][1] == 'd'
		&& mysh->arg[0][2] == '\0') {
			mysh->next = -1;
			if (mysh->nb_arg > 2) {
				my_putstr("cd: Too many arguments.\n");
				mysh->ex_val = 1;
				return;
			}
			check_arg(mysh);
		}
	}
}
