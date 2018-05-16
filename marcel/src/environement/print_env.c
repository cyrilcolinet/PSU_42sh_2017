/*
** EPITECH PROJECT, 2018
** print_env
** File description:
** minishell2
*/

#include "minishell2.h"

static void env_cas(mysh_t *mysh)
{
	int nb = my_strlen(mysh->arg[0]);
	char *str = "env";
	int n = 0;

	if (nb == 3) {
		for (int i = 0; str[i] != '\0'; i++) {
			if (mysh->arg[0][i] == str[i])
				n++;
		}
	}
	if (n == 3) {
		for (int i = 0; mysh->env[i] != NULL; i++) {
			my_putstr(mysh->env[i]);
			my_putchar('\n');
		}
		mysh->ex_val = 0;
		mysh->next = 0;
	}
}

static void setenv_cas(mysh_t *mysh)
{
	int nb = my_strlen(mysh->arg[0]);
	char *str = "setenv";
	int n = 0;

	if (nb == 6) {
		for (int i = 0; str[i] != '\0'; i++) {
			if (mysh->arg[0][i] == str[i])
				n++;
		}
	}
	if (n == 6) {
		for (int i = 0; mysh->env[i] != NULL; i++) {
			my_putstr(mysh->env[i]);
			my_putchar('\n');
		}
		mysh->ex_val = 0;
		mysh->next = 0;
	}
}

void print_env(mysh_t *mysh)
{
	if (mysh->nb_arg == 1) {
		env_cas(mysh);
		setenv_cas(mysh);
	}
}
