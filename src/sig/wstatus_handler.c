/*
** EPITECH PROJECT, 2018
** w_status
** File description:
** 42
*/

# include "shell.h"

static void print_stderr(char *msg, int wstatus)
{
	int err = 0;

	err = write(1, msg, my_strlen(msg));
	if (err == -1)
		perror(msg);
	if (WCOREDUMP(wstatus))
		write(1, " (core dumped)", 14);
	my_putchar('\n');
}

void print_status(int termsig, int wstatus)
{
	char *sig_str = strsignal(termsig);

	if (my_strequ(sig_str, "Floating point exception"))
		sig_str = "Floating exception";

	print_stderr(sig_str, wstatus);
}

void wstatus_handler(pid_t pid, env_t *env)
{
	int wait_ret = -1;
	int status = 0;
	int termsig = 0;

	wait_ret = waitpid(pid, &status, WUNTRACED | WCONTINUED);

	if (WIFSIGNALED(status) && !WIFEXITED(status)) {
		termsig = WTERMSIG(status);
		if (termsig != 0) {
			print_status(termsig, status);
			env->exit_code = (128 + termsig);
		}
	}

	kill(wait_ret, SIGKILL);
}
