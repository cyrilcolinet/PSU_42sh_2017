/*
** EPITECH PROJECT, 2018
** redirect
** File description:
** minishell2
*/

#include "minishell2.h"

static char *add_string(char *s, char *str, int n, int nb)
{
	char *new = NULL;
	int len = my_strlen(s) + my_strlen(str) + nb;

	new = malloc(sizeof(char) * (len + 1));
	new[len] = '\0';
	for (int i = 0; s[i] != '\0'; i++) {
		new[n] = s[i];
		n++;
	}
	if (str[0] != '>' && str[0] != '<') {
		new[n] = ' ';
		n++;
	}
	for (int i = 0; str[i] != '\0'; i++) {
		new[n] = str[i];
		n++;
	}
	free(s);
	return (new);
}

static char *make_a_string(mysh_t *mysh)
{
	char *s = NULL;
	int len = 0;
	int n = 0;
	int nb = 0;

	s = malloc(sizeof(char) * 1);
	s[0] = '\0';
	for (int i = 0; mysh->arg[i] != NULL; i++) {
		n = 0;
		nb = 0;
		if (mysh->arg[i][0] != '>' && mysh->arg[i][0] != '<')
			nb++;
		s = add_string(s, mysh->arg[i], n, nb);
	}
	return (s);
}

int call_redirect(mysh_t *mysh, int nb)
{
	char *str = NULL;

	mysh->nb_arg = 1;
	str = make_a_string(mysh);
	my_freetab(mysh->arg);
	str = clear_str(str);
	redirect_get_args(mysh, str);
	nb = redirect_function(mysh, nb);
	free(str);
	my_freetab(mysh->file);
	return (nb);
}
