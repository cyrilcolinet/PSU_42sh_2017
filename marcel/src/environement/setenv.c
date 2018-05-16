/*
** EPITECH PROJECT, 2018
** setenv
** File description:
** minishell2
*/

#include "minishell2.h"

static char *change_str(mysh_t *mysh)
{
	char *str;
	int len = my_strlen(mysh->name);
	int len2 = my_strlen(mysh->value);
	int i = 0;

	str = malloc(sizeof(char) * (len + len2 + 2));
	for (; mysh->name[i] != '\0'; i++)
		str[i] = mysh->name[i];
	str[i] = '=';
	i++;
	if (len2 == 0) {
		str[i] = '\0';
		return (str);
	}
	for (int j = 0; mysh->value[j] != '\0'; j++) {
		str[i] = mysh->value[j];
		i++;
	}
	str[i] = '\0';
	return (str);
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

int my_setenv(mysh_t *mysh)
{
	int nb = check_name(mysh);

	if (nb == -1) {
		mysh->env = add_env(mysh);
		mysh->ex_val = 0;
		mysh->next = 0;
		return (0);
	} else if (nb > -1) {
		if (mysh->overwrite != 0) {
			free(mysh->env[nb]);
			mysh->env[nb] = change_str(mysh);
			mysh->ex_val = 0;
			mysh->next = 0;
			return (0);
		}
	}
	return (0);
}
