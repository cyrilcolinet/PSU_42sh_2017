/*
** EPITECH PROJECT, 2018
** my_get_all_arg
** File description:
** mnshell
*/

#include "minishell2.h"

static bool is_end(char *s, int i)
{
	i++;
	for (; s[i] != ';' && s[i] != '\0'; i++) {
		if (s[i] != ' ')
			return (false);
	}
	return (true);
}

static char *get_arg(mysh_t *mysh, char *s, int k, int j)
{
	char *str;
	int len = 0;

	while ((s[mysh->save] == ' ' || s[mysh->save] == ';')
	&& s[mysh->save] != '\0')
		mysh->save++;
	for (int i = mysh->save; s[i] != ' ' && s[i] != ';'
		&& s[i] != '\0'; i++)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	for (j = mysh->save; s[j] != ' ' && s[j] != ';'
		&& s[j] != '\0'; j++) {
		str[k] = s[j];
		k++;
	}
	for (; (s[j] == ' ' || s[j] == ';') && s[j] != '\0'; j++)
		len++;
	mysh->save += len;
	return (str);
}

static void get_args(mysh_t *mysh, char *s, int n)
{
	int j = 0;
	int k = 0;

	mysh->nb_arg = 1;
	for (int i = mysh->save; s[i] != ';' && s[i] != '\0'; i++) {
		if (s[i] == ' ' && s[i + 1] != '\0' && s[i + 1] != ';')
			mysh->nb_arg++;
	}
	mysh->all_arg[n] = malloc(sizeof(char *) * (mysh->nb_arg + 1));
	mysh->all_arg[n][mysh->nb_arg] = NULL;
	for (int i = 0; i < mysh->nb_arg; i++) {
		k = 0;
		j = 0;
		mysh->all_arg[n][i] = get_arg(mysh, s, k, j);
	}
}

bool my_get_all_arg(mysh_t *mysh, char *s)
{
	mysh->nb_all_arg = 1;
	mysh->save = 0;
	if (!check_redirect_error(mysh, s) || !check_pipe_error(mysh, s)) {
		mysh->ex_val = 1;
		return (false);
	}
	if (s[0] == ';')
		mysh->nb_all_arg--;
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == ';' && !is_end(s, i))
			mysh->nb_all_arg++;
	}
	mysh->all_arg = malloc(sizeof(char **) * (mysh->nb_all_arg + 1));
	mysh->all_arg[mysh->nb_all_arg] = NULL;
	for (int i = 0; i < mysh->nb_all_arg; i++)
		get_args(mysh, s, i);
	return (true);
}
