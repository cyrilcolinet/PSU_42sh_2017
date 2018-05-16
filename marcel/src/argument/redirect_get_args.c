/*
** EPITECH PROJECT, 2018
** redirect_get_args
** File description:
** minishell2
*/

#include "minishell2.h"

static char *get_arg_rd(mysh_t *mysh, char *s, int a, int b)
{
	char *str = NULL;
	int len = 0;

	if (s[mysh->save] == '-')
		while (s[mysh->save] == ' ' && s[mysh->save] == '\0')
			mysh->save++;
	for (int i = mysh->save; s[i] != ' ' && s[i] != '\0'; i++)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	for (a = mysh->save; s[a] != ' ' && s[a] != '\0'; a++) {
		str[b] = s[a];
		b++;
	}
	for (; s[a] == ' ' && s[a] != '\0'; a++)
		len++;
	mysh->save += len;
	return (str);
}

static char *get_arg_true(mysh_t *mysh, char *s, int a, int b)
{
	char *str = NULL;
	int len = 0;

	for (int i = mysh->save; s[i] != '-' && s[i] != '\0'; i++)
		mysh->save++;
	for (int i = mysh->save; s[i] != ' ' && s[i] != '\0'; i++)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	for (a = mysh->save; s[a] != ' ' && s[a] != '\0'; a++) {
		str[b] = s[a];
		b++;
	}
	for (; s[a] == ' ' && s[a] != '\0'; a++)
		len++;
	mysh->save += len;
	return (str);
}

static char *get_arg_false(mysh_t *mysh, char *s, int a, int b)
{
	char *str = NULL;
	int len = 0;

	for (int i = mysh->save; s[i] != ' ' && s[i] != '<'
	&& s[i] != '>' && s[i] != '\0'; i++)
		len++;
	if (s[mysh->save + len] == '>' || s[mysh->save + len] == '>')
		mysh->redi = true;
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	for (a = mysh->save; s[a] != ' ' && s[a] != '<'
	&& s[a] != '>' && s[a] != '\0'; a++) {
		str[b] = s[a];
		b++;
	}
	for (; s[a] == ' ' && s[a] != '\0'; a++)
		len++;
	mysh->save += len;
	return (str);
}

static void get_args(mysh_t *mysh, char *s)
{
	mysh->file[mysh->nb_file] = NULL;
	mysh->arg = malloc(sizeof(char *) * (mysh->nb_arg + 1));
	mysh->arg[mysh->nb_arg] = NULL;
	for (int i = 0; i < mysh->nb_arg; i++) {
		if (!mysh->redi)
			mysh->arg[i] = get_arg_false(mysh, s, 0, 0);
		else
			mysh->arg[i] = get_arg_true(mysh, s, 0, 0);
	}
	mysh->save = 0;
	get_type_redirect(mysh, s);
	if (s[mysh->save] == ' ')
		mysh->save++;
	for (int i = 0; i < mysh->nb_file; i++)
		mysh->file[i] = get_arg_rd(mysh, s, 0, 0);
}

void redirect_get_args(mysh_t *mysh, char *s)
{
	int i = 0;

	mysh->nb_file = 1;
	mysh->save = 0;
	for (; s[i] != '<' && s[i] != '>' && s[i] != '\0'; i++) {
		if (s[i] == ' ' && (s[i + 1] != '>' && s[i + 1] != '<'))
			mysh->nb_arg++;
	}
	if ((s[i] == '>' || s[i] == '<') && (s[i + 1] == ' ' ||
	((s[i + 1] == '>' || s[i + 1] == '<') && s[i + 2] == ' ')))
		mysh->nb_file--;
	for (; s[i] != '\0'; i++) {
		if (s[i] == ' ' && s[i + 1] == '-' &&
		(s[i - 1] != '<' && s[i - 1] != '>'))
			mysh->nb_arg++;
		else if (s[i] == ' ')
			mysh->nb_file++;
	}
	mysh->file = malloc(sizeof(char *) * (mysh->nb_file + 1));
	get_args(mysh, s);
}
