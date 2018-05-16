/*
** EPITECH PROJECT, 2018
** my_get_arg
** File description:
** mnshell
*/

#include "minishell2.h"

static char *get_arg(mysh_t *mysh, char *s)
{
	char *str;
	int len = 0;
	int k = 0;

	for (int i = mysh->save; s[i] != ' ' && s[i] != '\0'; i++) {
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	for (int j = mysh->save; s[j] != ' ' && s[j] != '\0'; j++) {
		str[k] = s[j];
		k++;
		len = j + 1;
	}
	mysh->save = len + 1;
	return (str);
}

void my_get_arg(mysh_t *mysh, char *s)
{
	mysh->nb_arg = 0;
	mysh->save = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == ' ') {
			mysh->nb_arg++;
		}
	}
	mysh->nb_arg++;
	mysh->arg = malloc(sizeof(char *) * (mysh->nb_arg + 1));
	mysh->arg[mysh->nb_arg] = NULL;
	for (int i = 0; i < mysh->nb_arg; i++)
		mysh->arg[i] = get_arg(mysh, s);
}
