/*
** EPITECH PROJECT, 2018
** get_type_redirect
** File description:
** minishell2
*/

#include "minishell2.h"

void get_type_redirect(mysh_t *mysh, char *s)
{
	int nb = mysh->save;

	while (s[nb] != '<' && s[nb] != '>')
		nb++;
	if (s[nb] == '>' && s[nb + 1] != '>') {
		mysh->redirect = 1;
		nb++;
	} else if (s[nb] == '>' && s[nb + 1] == '>') {
		mysh->redirect = 3;
		nb += 2;
	}
	if (s[nb] == '<' && s[nb + 1] != '<') {
		mysh->redirect = 2;
		nb++;
	} else if (s[nb] == '<' && s[nb + 1] == '<') {
		mysh->redirect = 4;
		nb += 2;
	}
	mysh->save = nb;
}
