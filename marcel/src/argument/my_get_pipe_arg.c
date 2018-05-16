/*
** EPITECH PROJECT, 2018
** my_get_pipe_arg
** File description:
** mnshell
*/

#include "minishell2.h"

static char * get_arg(mysh_t *mysh, char *s, int a, int b)
{
	char *str = NULL;
	int len = 0;
	int nb = mysh->save;

	while ((s[nb] == ' ' || s[nb] == '|') && s[nb] != '\0')
		nb++;
	for (int i = nb; s[i] != ' ' && s[i] != '|' && s[i] != '\0'; i++)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	for (b = nb; s[b] != ' ' && s[b] != '|' && s[b] != '\0'; b++) {
		str[a] = s[b];
		a++;
	}
	for (; (s[b] == ' ' || s[b] == '|') && s[b] != '\0'; b++)
		len++;
	mysh->save = nb;
	mysh->save += len;
	return (str);
}

static void get_args(mysh_t *mysh, char *s, int n)
{
	int a = 0;
	int b = 0;
	int nb = 1;

	for (int i = mysh->save; s[i] != '|' && s[i] != '\0'; i++)
		if (i > 1 && s[i - 1] != '|' && s[i] == ' '
		&& (s[i + 1] != '\0' && s[i + 1] != '|'))
			nb++;
	mysh->pipe_arg[n] = malloc(sizeof(char *) * (nb + 1));
	mysh->pipe_arg[n][nb] = NULL;
	for (int k = 0; k < nb; k++) {
		a = 0;
		b = 0;
		mysh->pipe_arg[n][k] = get_arg(mysh, s, a, b);
		mysh->pipe_arg[n][k] = clear_str(mysh->pipe_arg[n][k]);
	}
}

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
	if (str[0] != '|') {
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

static char *make_a_string(mysh_t *mysh, int x)
{
	char *s = NULL;
	int len = 0;
	int n = 0;
	int nb = 0;

	s = malloc(sizeof(char) * 1);
	s[0] = '\0';
	for (int i = 0; mysh->all_arg[x][i] != NULL; i++) {
		n = 0;
		nb = 0;
		if (mysh->all_arg[x][i][0] != '|')
			nb++;
		s = add_string(s, mysh->all_arg[x][i], n, nb);
	}
	return (s);
}

void my_get_current_pipe_arg(mysh_t *mysh, int x)
{
	bool pipe = false;
	char *str = NULL;

	for (int i = 0; mysh->all_arg[x][i] != NULL; i++)
		for (int j = 0; mysh->all_arg[x][i][j] != '\0'; j++)
			if (mysh->all_arg[x][i][j] == '|')
				pipe = true;
	if (pipe == false) {
		just_copy_all_arg(mysh, x);
		return;
	}
	str = make_a_string(mysh, x);
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == '|')
			mysh->nb_pipe++;
	mysh->pipe_arg = malloc(sizeof(char **) * (mysh->nb_pipe + 1));
	mysh->pipe_arg[mysh->nb_pipe] = NULL;
	for (int i = 0; i < mysh->nb_pipe; i++)
		get_args(mysh, str, i);
	free(str);
}
