/*
** EPITECH PROJECT, 2018
** copy_env
** File description:
** minishell2
*/

#include "minishell2.h"

static char *copy_str(char *env)
{
	char *str;
	int nb = 0;

	for (int i = 0; env[i] != '\0'; i++) {
		nb = i + 1;
	}
	str = malloc(sizeof(char) * (nb + 1));
	str[nb] = '\0';
	for (int i = 0; env[i] != '\0'; i++) {
		str[i] = env[i];
	}
	return (str);
}

char **copy_env(char **env)
{
	char **new_env;
	int nbstr = 0;

	for (int i = 0; env[i] != NULL; i++) {
		nbstr = i + 1;
	}
	new_env = malloc(sizeof(char *) * (nbstr + 1));
	new_env[nbstr] = NULL;
	for (int i = 0; env[i] != NULL; i++) {
		new_env[i] = copy_str(env[i]);
	}
	return (new_env);
}

char *copy_home(mysh_t *mysh)
{
	char *str;
	int nb = 0;
	int len = 0;

	for (int i = 0; mysh->env[i] != NULL; i++)
		if (mysh->env[i][0] == 'H' && mysh->env[i][1] == 'O'
		&& mysh->env[i][2] == 'M' && mysh->env[i][3] == 'E'
		&& mysh->env[i][4] == '=')
			nb = i;
	for (int i = 5; mysh->env[nb][i] != '\0'; i++)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	len = 0;
	for (int i = 5; mysh->env[nb][i] != '\0'; i++) {
		str[len] = mysh->env[nb][i];
		len++;
	}
	return (str);
}
