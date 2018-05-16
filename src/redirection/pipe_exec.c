/*
** EPITECH PROJECT, 2018
** my_exec
** File description:
** minishell
*/

#include "minishell.h"

void		dup_child(int stdout_holder, int pipe_fd[2],
				int *fd_transfer, int is_next)
{
	stdout_holder = dup(1);
	if (is_next == 1) {
		dup2(*fd_transfer, 0);
		close(pipe_fd[0]);
	}
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	stdout_holder = stdout_holder;
}

void		exec_pipe(char **cmd, int *fd_transfer, env_t *env,
				int is_next)
{
	int	pipe_fd[2];
	pid_t	pid;
	int	status;
	int	stdout_holder = 1;

	pipe(pipe_fd);
	pid = fork();
	env->str_env = my_list_to_array(env);
	if (pid == 0) {
		dup_child(stdout_holder, pipe_fd, fd_transfer, is_next);
		execve(cmd[0], cmd, env->str_env);
		dup2(stdout_holder, 1);
		close(stdout_holder);
	} else {
		waitpid(pid, &status, 0);
		close(pipe_fd[1]);
		*fd_transfer = pipe_fd[0];
	}
}

void		exec_all_pipe(p_pipe_t *pipe, env_t *env)
{
	p_pipe_t	*tmp = pipe;
	char		**tab_left = NULL;
	int		fd_transfer = 1;
	int		next;

	while (tmp) {
		tab_left = my_str_to_word_array(tmp->pipe_cmd, ' ');
		next = (tmp->next == NULL) ? 0 : 1;
		exec_pipe(tab_left, &fd_transfer, env, next);
		tmp = tmp->next;
		free(tab_left);
	}
}