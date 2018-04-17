/*
** EPITECH PROJECT, 2018
** main
** File description:
** 42 bootstrap
*/

#include "bootstrap.h"

/* void		dup_child(int stdout_holder, int pipe_fd[2], */
/* 				int *fd_transfer, int is_next) */
/* { */
/* 	stdout_holder = dup(1); */
/* 	if (is_next == 1) { */
/* 		dup2(*fd_transfer, 0); */
/* 		close(pipe_fd[0]); */
/* 	} */
/* 	dup2(pipe_fd[1], 1); */
/* 	close(pipe_fd[1]); */
/* 	stdout_holder = stdout_holder; */
/* } */

/* void		exec_pipe(char **cmd, int *fd_transfer, env_t *env, */
/* 				int is_next) */
/* { */
/* 	int	pipe_fd[2]; */
/* 	pid_t	pid; */
/* 	int	status; */
/* 	int	stdout_holder = 1; */

/* 	pipe(pipe_fd); */
/* 	pid = fork(); */
/* 	env->str_env = my_list_to_array(env); */
/* 	if (pid == 0) { */
/* 		dup_child(stdout_holder, pipe_fd, fd_transfer, is_next); */
/* 		execve(cmd[0], cmd, env->str_env); */
/* 		dup2(stdout_holder, 1); */
/* 		close(stdout_holder); */
/* 	} else { */
/* 		waitpid(pid, &status, 0); */
/* 		close(pipe_fd[1]); */
/* 		*fd_transfer = pipe_fd[0]; */
/* 	} */
/* } */

/* void		exec_all_pipe(p_pipe_t *pipe, env_t *env) */
/* { */
/* 	p_pipe_t	*tmp = pipe; */
/* 	char		**tab_left = NULL; */
/* 	int		fd_transfer = 1; */
/* 	int		next; */

/* 	while (tmp) { */
/* 		tab_left = my_str_to_word_array(tmp->pipe_cmd, ' '); */
/* 		next = (tmp->next == NULL) ? 0 : 1; */
/* 		exec_pipe(tab_left, &fd_transfer, env, next); */
/* 		tmp = tmp->next; */
/* 		free(tab_left); */
/* 	} */
/* } */

int bootstrap(char **av)
{
	char ***arg;

	arg = malloc(sizeof(char **) * 4);
	arg[3] = NULL;
	for (int i = 0; i < 3; i++) {
		arg[i] = my_strtok(av[ i+ 1], ' ');
	}
	for (int i = 0; arg[i] != NULL; i++) {
		for (int j = 0; arg[i][j] != NULL; j++) {
			my_putstr("ARG ");
			my_putstr("i = ");
			my_put_nbr(i);
			my_putstr(" j = ");
			my_put_nbr(j);
			my_putstr("   ");
			my_putstr(arg[i][j]);
			my_putstr("\n");
		}
	}
	return (0);
}

int main(int ac, char **av, char **env)
{
	int res = 84;

	if (*env == NULL)
		return (84);

	if (ac != 4) {
		write(1, "Wrong arguments number.\n", 24);
		return (84);
	}

	res =bootstrap(av);
	return (res);
}
