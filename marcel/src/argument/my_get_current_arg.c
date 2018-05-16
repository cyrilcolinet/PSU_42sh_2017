/*
** EPITECH PROJECT, 2018
** my_get_current_arg
** File description:
** mnshell
*/

#include "minishell2.h"

static char *copy(char *s)
{
	char *str;

	str = malloc(sizeof(char) * (my_strlen(s) + 1));
	str[my_strlen(s)] = '\0';
	for (int i = 0; s[i] != '\0'; i++)
		str[i] = s[i];
	str = clear_str(str);
	return (str);
}

void my_get_current_arg(mysh_t *mysh, int x)
{
	mysh->nb_arg = 0;
	for (int i = 0; mysh->pipe_arg[x][i] != NULL; i++)
		mysh->nb_arg++;
	mysh->arg = malloc(sizeof(char *) * (mysh->nb_arg + 1));
	mysh->arg[mysh->nb_arg] = NULL;
	for (int i = 0; i < mysh->nb_arg; i++) {
		mysh->arg[i] = copy(mysh->pipe_arg[x][i]);
	}
}
