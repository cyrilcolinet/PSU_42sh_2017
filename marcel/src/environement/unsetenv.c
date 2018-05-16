/*
** EPITECH PROJECT, 2018
** unsetenv
** File description:
** minishell2
*/

#include "minishell2.h"

static char *copy_str(char *env)
{
	char *str;
	int nb = 0;

	for (int i = 0; env[i] != '\0'; i++) {
		nb = i + 1;
	}
	str = malloc(sizeof(char) * (nb + 1));
	str[nb] = '\0';
	for (int i = 0; env[i] != '\0'; i++) {
		str[i] = env[i];
	}
	return (str);
}

static char **supp_str(mysh_t *mysh, int nb)
{
	char **new_env;
	int nbstr = 0;
	int k = 0;

	for (int i = 0; mysh->env[i] != NULL; i++)
		nbstr = i + 1;
	new_env = malloc(sizeof(char *) * (nbstr));
	new_env[nbstr - 1] = NULL;
	for (int i = 0; mysh->env[i] != NULL; i++) {
		if (i == nb) {
			if (mysh->env[i + 1] != NULL) {
				i++;
				new_env[k] = copy_str(mysh->env[i]);
			}
		} else if (i != nb)
			new_env[k] = copy_str(mysh->env[i]);
		k++;
	}
	my_freetab(mysh->env);
	return (new_env);
}

static int check_name(mysh_t *mysh)
{
	int len = my_strlen(mysh->name);
	int nb = 0;

	for (int i = 0; mysh->env[i] != NULL; i++) {
		nb = 0;
		for (int j = 0; mysh->name[j] != '\0'; j++) {
			if (mysh->name[j] == mysh->env[i][j])
				nb++;
		}
		if (nb == len)
			return (i);
	}
	return (-1);
}

int my_unsetenv(mysh_t *mysh)
{
	int nb = check_name(mysh);

	mysh->next = 0;
	if (nb > -1) {
		mysh->env = supp_str(mysh, nb);
		mysh->ex_val = 0;
		return (0);
	}
	return (0);
}
