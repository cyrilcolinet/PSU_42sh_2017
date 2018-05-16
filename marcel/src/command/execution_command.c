/*
** EPITECH PROJECT, 2018
** execution_command
** File description:
** minishell2
*/

#include "minishell2.h"

static bool check_is_bin(mysh_t *mysh, char *name)
{
	int len = my_strlen(mysh->arg[0]);
	int len2 = my_strlen(name);
	int nb = 0;

	if (len != len2)
		return (false);
	for (int i = 0; mysh->arg[0][i] != '\0'; i++)
		if (mysh->arg[0][i] == name[i])
			nb++;
	if (nb == len) {
		return (true);
	}
	return (false);
}

static bool is_floating_point(int status)
{
	char *str = "Floating point exception";
	char *s = strsignal(WTERMSIG(status));

	for (int i = 0; s[i] != '\0'; i++)
		if (s[i] != str[i])
			return (false);
	my_putstr("Floating exception");
	return (true);
}

static void print_error(mysh_t *mysh, int status)
{
	if (WTERMSIG(status) != SIGINT) {
		if (!is_floating_point(status))
			my_putstr(strsignal(WTERMSIG(status)));
		if (WCOREDUMP(status))
			my_putstr(" (core dumped)");
		my_putstr("\n");
		mysh->ex_val = WTERMSIG(status) + 128;
	}
}

void execution_command(mysh_t *mysh, char *name)
{
	pid_t child = fork();
	int status = 0;
	pid_t wait_status = 0;

	if (check_is_bin(mysh, name))
		mysh->state = false;
	if (child < 0)
		perror("fork error\n");
	else if (child == 0) {
		execve(name, mysh->arg, mysh->env);
	} else {
		wait_status = wait(&status);
		mysh->ex_val = 0;
		if (WTERMSIG(status) != 0)
			print_error(mysh, status);
	}
	kill(wait_status, SIGKILL);
}
