/*
** EPITECH PROJECT, 2018
** check_tiret
** File description:
** minishell2
*/

#include "minishell2.h"

void get_new_hist(mysh_t *mysh)
{
	char buf[256];

	getcwd(buf, 256);
	if (mysh->hist != NULL) {
		chdir(mysh->hist);
		free(mysh->hist);
	}
	mysh->hist = malloc(sizeof(char) * (my_strlen(buf) + 1));
	for (int i = 0; i < my_strlen(buf); i++)
		mysh->hist[i] = buf[i];
	mysh->hist[my_strlen(buf)] = '\0';
}

int check_tiret(mysh_t *mysh)
{
	if (mysh->nb_arg == 2 && mysh->arg[1][0] == '-'
	&& mysh->arg[1][1] == '\0') {
		if (mysh->hist == NULL) {
			my_putstr(": No such file or directory.\n");
			mysh->ex_val = 1;
			return (0);
		} else if (mysh->hist != NULL) {
			get_new_hist(mysh);
		}
		return (0);
	}
	return (1);
}

int check_wave(mysh_t *mysh)
{
	if (mysh->nb_arg == 2 && mysh->arg[1][0] == '~'
	&& mysh->arg[1][1] == '\0') {
		if (mysh->home[0] == '\0') {
			my_putstr(": No such file or directory.\n");
			mysh->ex_val = 1;
			return (1);
		}
		get_new_hist(mysh);
		chdir(mysh->home);
		return (0);
	}
	return (1);
}
