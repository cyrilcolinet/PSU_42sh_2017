/*
** EPITECH PROJECT, 2018
** call_setenv
** File description:
** minishell2
*/

#include "minishell2.h"

static int get_name(mysh_t *mysh)
{
	int len = my_strlen(mysh->arg[1]);

	if ((mysh->arg[1][0] >= 'A' && mysh->arg[1][0] <= 'Z')
	|| (mysh->arg[1][0] >= 'a' && mysh->arg[1][0] <= 'z')) {
		if (mysh->name != NULL)
			free(mysh->name);
		mysh->name = malloc(sizeof(char) * (len + 1));
		for (int i = 0; mysh->arg[1][i] != '\0'; i++) {
			mysh->name[i] = mysh->arg[1][i];
		}
		mysh->name[len] = '\0';
		return (0);
	}
	my_putstr("setenv: Variable name must");
	my_putstr(" begin with a letter.\n");
	mysh->next = -1;
	mysh->ex_val = 1;
	return (-1);
}

static void get_value(mysh_t *mysh)
{
	int len = my_strlen(mysh->arg[2]);

	if (len > 0) {
		if (mysh->value != NULL)
			free(mysh->value);
		mysh->value = malloc(sizeof(char) * (len + 1));
		for (int i = 0; mysh->arg[2][i] != '\0'; i++) {
			mysh->value[i] = mysh->arg[2][i];
		}
		mysh->value[len] = '\0';
	} else
		mysh->value = NULL;
}

static void check_name(mysh_t *mysh)
{
	int err = 0;
	int nb;

	for (int i = 0; mysh->arg[1][i] != '\0'; i++)
		if (mysh->arg[1][i] == '=') {
			err = -1;
			my_putstr("setenv: Variable name must");
			my_putstr(" contain alphanumeric characters.\n");
			mysh->next = -1;
			mysh->ex_val = 1;
			return;
		}
	if (err == 0)
		nb = my_setenv(mysh);
}

static void take_name_arg(mysh_t *mysh)
{
	int err = 0;

	if (mysh->nb_arg > 3) {
		my_putstr("setenv: Too many arguments.\n");
		mysh->next = -1;
		mysh->ex_val = 1;
	} else if (mysh->nb_arg == 2 || mysh->nb_arg == 3) {
		err = get_name(mysh);
		get_value(mysh);
		if (err == 0) {
			check_name(mysh);
		}
	}
}

void call_setenv(mysh_t *mysh)
{
	int nb = 0;
	char *str = "setenv";
	int len = my_strlen(str);
	int len2 = my_strlen(mysh->arg[0]);

	for (int i = 0; mysh->arg[0][i] != '\0'; i++) {
		if (mysh->arg[0][i] == str[i])
			nb++;
	}
	if (len == len2 && nb == len) {
		take_name_arg(mysh);
	}
}
