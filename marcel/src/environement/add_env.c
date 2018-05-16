/*
** EPITECH PROJECT, 2018
** add_env
** File description:
** minishell2
*/

#include "minishell2.h"

static char *add_str(mysh_t *mysh)
{
	char *str;
	int len = my_strlen(mysh->name);
	int len2 = my_strlen(mysh->value);
	int i = 0;

	str = malloc(sizeof(char) * (len + len2 + 2));
	for (; mysh->name[i] != '\0'; i++)
		str[i] = mysh->name[i];
	str[i] = '=';
	i++;
	if (len2 == 0) {
		str[i] = '\0';
		return (str);
	}
	for (int j = 0; mysh->value[j] != '\0'; j++) {
		str[i] = mysh->value[j];
		i++;
	}
	str[i] = '\0';
	return (str);
}

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

char **add_env(mysh_t *mysh)
{
	char **new_env;
	int nbstr = 0;

	for (int i = 0; mysh->env[i] != NULL; i++) {
		nbstr = i + 1;
	}
	new_env = malloc(sizeof(char *) * (nbstr + 2));
	new_env[nbstr] = add_str(mysh);
	new_env[nbstr + 1] = NULL;
	for (int i = 0; mysh->env[i] != NULL; i++) {
		new_env[i] = copy_str(mysh->env[i]);
	}
	my_freetab(mysh->env);
	return (new_env);
}
