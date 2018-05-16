/*
** EPITECH PROJECT, 2018
** call_unsetenv
** File description:
** minishell2
*/

#include "minishell2.h"

static int get_name(mysh_t *mysh, int n)
{
	int len = my_strlen(mysh->arg[n]);

	if (mysh->name != NULL)
		free(mysh->name);
	mysh->name = malloc(sizeof(char) * (len + 1));
	for (int i = 0; mysh->arg[n][i] != '\0'; i++) {
		mysh->name[i] = mysh->arg[n][i];
	}
	mysh->name[len] = '\0';
	return (0);
}

static void take_name_arg(mysh_t *mysh)
{
	int err = 0;
	int nb;

	if (mysh->nb_arg == 1) {
		my_putstr("unsetenv: Too few arguments.\n");
		mysh->ex_val = 1;
		mysh->next = -1;
	} else if (mysh->nb_arg >= 2) {
		for (int n = 1; mysh->arg[n] != NULL; n++) {
			err = get_name(mysh, n);
			if (err == 0) {
				nb = my_unsetenv(mysh);
			}
		}
	}
}

void call_unsetenv(mysh_t *mysh)
{
	char *str = "unsetenv";
	int len = my_strlen(str);
	int len2 = my_strlen(mysh->arg[0]);
	int nb = 0;

	for (int i = 0; mysh->arg[0][i] != '\0'; i++) {
		if (mysh->arg[0][i] == str[i])
			nb++;
	}
	if (len == len2 && nb == len) {
		take_name_arg(mysh);
	}
}
