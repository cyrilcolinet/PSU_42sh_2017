/*
** EPITECH PROJECT, 2018
** w_status
** File description:
** minishell
*/

#include "minishell.h"

void print_stderr(char *msg, int termsig)
{
	int err = 0;

	err = write(1, msg, my_strlen(msg));
	if (err == -1)
		perror(msg);
	if (WCOREDUMP(termsig))
		write(1, " (core dumped)\n", 16);
	else
		my_putchar('\n');
}

void print_compatible(int termsig, char *bin_cmd)
{
	if (termsig == SIGILL) {
		write(1, bin_cmd, my_strlen(bin_cmd));
		print_stderr(": Exec format error. Wrong Architecture.\n",
		termsig);
	}
}

void print_status(int termsig)
{
	switch (termsig) {
	case SIGHUP:
		print_stderr("Hangup (killed)\n", termsig);
		break;
	case SIGABRT:
		print_stderr("Aborted", termsig);
		break;
	case SIGFPE:
		print_stderr("Floating exception", termsig);
		break;
	case SIGSEGV:
		print_stderr("Segmentation fault", termsig);
		break;
	case SIGPIPE:
		print_stderr("Sigpipe (killed)\n", termsig);
		break;
	case SIGBUS:
		print_stderr("Bus error", termsig);
		break;
	}
}

void wstatus_handler(int wstatus, char *bin_cmd, pid_t pid, env_t *env)
{
	int termsig = 0;

	(void)pid;
	if (!WIFEXITED(wstatus)) {
		if (WIFSIGNALED(wstatus)) {
			termsig = WTERMSIG(wstatus);
			print_status(termsig);
			print_compatible(termsig, bin_cmd);
			env->exit_code = (128 + termsig);
		}
	}
}
