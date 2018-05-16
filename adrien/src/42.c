/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Made by developers
*/

#include "42.h"

void		loop_pipe(char ***cmd)
{
	int	p[2];
	pid_t	pid;
	int	fd_in = 0;

	while (*cmd != NULL) {
		pipe(p);
		if ((pid = fork()) == -1)
			exit(EXIT_FAILURE);
		else if (pid == 0) {
			dup2(fd_in, 0);
			if (*(cmd + 1) != NULL)
				dup2(p[1], 1);
			close(p[0]);
			execvp((*cmd)[0], *cmd);
			exit(EXIT_FAILURE);
		} else {
			wait(NULL);
			close(p[1]);
			fd_in = p[0];
			cmd++;
		}
	}
}

void		my_exec_cmds(t_mini *control)
{
	int	i = -1;

	while (control->cmds[++i]) {
		control->buffer = control->cmds[i];
		control->args = my_str_to_word_array(control->buffer, ' ');
		control->system = 0;
		my_cd(control);
		my_env(control);
		my_exit(control->buffer);
		if (!control->system) {
			if ((control->pid = fork()) == -1)
				exit(0);
			my_pid(control);
		}
		my_free_tab(control->args);
	}
}

void		my_exec_prompt(t_mini *control)
{
	while ((control->buffer = get_next_line(0)) != NULL) {
		if (my_strlen(control->buffer) <= 0) {
			my_prompt();
			continue;
		}
		control->cmds = my_str_to_word_array(control->buffer, ';');
		my_exec_cmds(control);
		my_free_tab(control->cmds);
		my_prompt();
	}
}

void		my_pid(t_mini *co)
{
	char	**tab = my_str_to_word_array(my_get_env(*co, "PATH"), ':');
	int	i = -1;

	if (co->pid != 0) {
		waitpid(co->pid, &co->status, 0);
		my_check_errors(co);
		my_free_tab(tab);
		return;
	}
	while (tab[++i])
		execve(my_strcat(tab[i], co->args[0], 1), co->args, co->env);
	my_execve(co);
	opendir(co->args[0]);
	my_putstr(co->args[0], 2);
	if ((my_str_start(co->args[0], "/") || my_str_start(co->args[0], "./")
		|| my_str_start(co->args[0], "../")) && errno != ENOTDIR)
		my_putstr(": Permission denied.\n", 2);
	else
		my_putstr(": Command not found.\n", 2);
	exit(1);
}

int		main(int ac, char **av, char **env)
{
	// char *ls[] = {"/bin/ls", "-l", "/dev", NULL};
	// char *grep[] = {"/bin/grep", "tty", NULL};
	// char *wc[] = {"/bin/more", NULL};
	// char **cmd[] = {ls, grep, wc, NULL};
	//
	// loop_pipe(cmd);
	// return (0);

	t_mini	control;

	(void)ac;
	(void)av;
	my_prompt();
	control.env = my_copy_env(env, 0);
	control.status = 0;
	my_exec_prompt(&control);
	return (control.status);
}
