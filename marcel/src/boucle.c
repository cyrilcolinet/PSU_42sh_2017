/*
** EPITECH PROJECT, 2018
** boucle
** File description:
** minishell2
*/

#include "minishell2.h"

int call_function(mysh_t *mysh, int nb)
{
	nb = check_exit(mysh);
	if (nb == 1 && mysh->next == 1) {
		check_env(mysh);
		call_cd(mysh);
		if (mysh->next == 1) {
			command(mysh);
		}
	}
	mysh->next = 1;
	return (nb);
}

static bool is_redirect(mysh_t *mysh)
{
	for (int a = 0; mysh->arg[a] != NULL; a++)
		for (int i = 0; mysh->arg[a][i] != '\0'; i++)
			if (mysh->arg[a][i] == '<'
			|| mysh->arg[a][i] == '>') {
				mysh->redi = false;
				return (true);
			}
	return (false);
}

static int third_boucle(int nb, mysh_t *mysh, int end)
{
	for (int j = 0; j < mysh->nb_pipe; j++) {
		my_get_current_arg(mysh, j);
		if (is_redirect(mysh))
			nb = call_redirect(mysh, nb);
		else
			nb = call_function(mysh, nb);
		if (nb < end)
			end = nb;
		my_freetab(mysh->arg);
	}
	for (int j = 0; mysh->pipe_arg[j] != NULL; j++)
		my_freetab(mysh->pipe_arg[j]);
	free(mysh->pipe_arg);
	return (end);
}

static int second_boucle(int nb, mysh_t *mysh)
{
	int end = 1;

	for (int i = 0; i < mysh->nb_all_arg; i++) {
		mysh->nb_pipe = 1;
		mysh->save = 0;
		my_get_current_pipe_arg(mysh, i);
		end = third_boucle(nb, mysh, end);
	}
	for (int i = 0; mysh->all_arg[i] != NULL; i++)
		my_freetab(mysh->all_arg[i]);
	free(mysh->all_arg);
	return (end);
}

void boucle(int nb, mysh_t *mysh, char *s)
{
	while (nb == 1) {
		signal(SIGINT, handler_int);
		if (isatty(0))
			my_putstr("$> ");
		s = get_next_line(0);
		if (s == NULL)
			return;
		if (s[0] != '\0') {
			s = clear_str(s);
			if (my_get_all_arg(mysh, s)) {
				nb = second_boucle(nb, mysh);
			}
		}
		free(s);
		mysh->next = 1;
	}
}
