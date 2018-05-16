/*
** EPITECH PROJECT, 2018
** command
** File description:
** minishell2
*/

#include "minishell2.h"

static char *add_name(mysh_t *mysh, char *name, char *s, int j)
{
	s[j] = '/';
	j++;
	for (int k = 0; name[k] != '\0'; k++) {
		s[j] = name[k];
		j++;
	}
	return (s);
}

static char *access_path(mysh_t *mysh, char *name, char *s)
{
	int len;

	for (int i = 0; mysh->path[i] != NULL; i++) {
		len = my_strlen(mysh->path[i]) + my_strlen(name) + 1;
		s = malloc(sizeof(char) * (len + 1));
		s[len] = '\0';
		for (len = 0; mysh->path[i][len] != '\0'; len++)
			s[len] = mysh->path[i][len];
		add_name(mysh, name, s, len);
		if ((access(s, F_OK)) == 0)
			return (s);
		else
			free(s);
	}
	return (NULL);
}

static char *check_access(mysh_t *mysh, char *name)
{
	char *s = NULL;

	if (mysh->path != NULL)
		if (!(name[0] == '.' && name[1] == '/')) {
			s = access_path(mysh, name, s);
		}
	if (s != NULL)
		return (s);
	if ((access(name, F_OK)) == 0)
		if (is_dir(mysh, name))
			return (NULL);
		else
			return (name);
	my_putstr(name);
	my_putstr(": Command not found.\n");
	mysh->ex_val = 1;
	return (NULL);
}

void command(mysh_t *mysh)
{
	char *name;

	name = check_access(mysh, mysh->arg[0]);
	if (name != NULL && !echo_ex_val(mysh))
		execution_command(mysh, name);
	if (mysh->state)
		free(name);
	mysh->state = true;
}
