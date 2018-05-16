/*
** EPITECH PROJECT, 2018
** mnshell
** File description:
** minishell2
*/

#include "minishell2.h"

static void free_all(mysh_t *mysh)
{
	if (mysh->home != NULL)
		free(mysh->home);
	if (mysh->hist != NULL)
		free(mysh->hist);
	if (mysh->name != NULL)
		free(mysh->name);
	if (mysh->value != NULL)
		free(mysh->value);
	my_freetab(mysh->env);
	my_freetab(mysh->path);
	free(mysh);
}

int minishell(int ac, char **av, char **environement)
{
	mysh_t *mysh = malloc(sizeof(mysh_t));
	int nb = 1;
	char *s;

	mysh->name = NULL;
	mysh->value = NULL;
	mysh->hist = NULL;
	mysh->next = 1;
	mysh->ex_val = 0;
	mysh->state = true;
	mysh->env = copy_env(environement);
	mysh->path = copy_path(mysh);
	mysh->home = copy_home(mysh);
	boucle(nb, mysh, s);
	nb = mysh->ex_val;
	free_all(mysh);
	return (nb);
}
