/*
** EPITECH PROJECT, 2018
** copy_path
** File description:
** minishell2
*/

#include "minishell2.h"

static int get_nb_arg(char *str)
{
	int nb = 1;

	if (my_strlen(str) == 5)
		return (0);
	for (int i = 4; str[i] != '\0'; i++)
		if (str[i] == ':' && str[i + 1] != '\0')
			nb++;
	return (nb);
}

static int len_str(char *str, int nb)
{
	int len = 0;

	for (int i = nb; str[i] != '\0' && str[i] != ':'; i++) {
		len++;
	}
	return (len);
}

static char *get_str(char *str)
{
	static int save = 5;
	int len = 0;
	int k = 0;
	char *s;

	len = len_str(str, save);
	s = malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	for (; str[save] != '\0' && str[save] != ':'; save++) {
		s[k] = str[save];
		k++;
	}
	if (str[save] == ':')
		save++;
	return (s);
}

static char **take_path(char *str)
{
	char **s;
	int nb_arg = get_nb_arg(str);

	s = malloc(sizeof(char *) * (nb_arg + 1));
	s[nb_arg] = NULL;
	for (int i = 0; i < nb_arg; i++) {
		s[i] = get_str(str);
	}
	return (s);
}

char **copy_path(mysh_t *mysh)
{
	char **s = NULL;

	for (int i = 0; mysh->env[i] != NULL; i++) {
		if (mysh->env[i][0] == 'P' && mysh->env[i][1] == 'A'
		&& mysh->env[i][2] == 'T' && mysh->env[i][3] == 'H'
		&& mysh->env[i][4] == '=') {
			s = take_path(mysh->env[i]);
		}
	}
	return (s);
}
