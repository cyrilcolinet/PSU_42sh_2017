/*
** EPITECH PROJECT, 2018
** my_get_pipe_copy_arg
** File description:
** minishell
*/

#include "minishell2.h"

static char *copy(char *s)
{
	char *str;

	str = malloc(sizeof(char) * (my_strlen(s) + 1));
	str[my_strlen(s)] = '\0';
	for (int i = 0; s[i] != '\0'; i++)
		str[i] = s[i];
	return (str);
}

void just_copy_all_arg(mysh_t *mysh, int x)
{
	int n = 0;

	mysh->pipe_arg = malloc(sizeof(char **) * (2));
	mysh->pipe_arg[1] = NULL;
	for (int i = 0; mysh->all_arg[x][i] != NULL; i++)
		n++;
	mysh->pipe_arg[0] = malloc(sizeof(char *) * (n + 1));
	mysh->pipe_arg[0][n] = NULL;
	for (int i = 0; i < n; i++) {
		mysh->pipe_arg[0][i] = copy(mysh->all_arg[x][i]);
	}
}
