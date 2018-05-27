/*
** EPITECH PROJECT, 2018
** call
** File description:
** 42
*/

# include "shell.h"

void call_builtins(int func, char **av, env_t *env, parser_t *parser)
{
	void (*builtins[8])(env_t *, char **) = {
		my_cd, my_setenv_cmd, my_unsetenv_cmd, my_env,
		my_echo, my_alias, del_variable_in_shell
	};
	if (func == 4)
		exit_success(env, av, parser);
	else {
		dup2(env->pipe_fdin, 0);
		close(env->pipe_fdin);
		if (env->pipe_next) {
			dup2(env->pipe_fd[1], 1);
			close(env->pipe_fd[1]);
		}
		close(env->pipe_fd[0]);
		if (func > 4)
			func--;
		builtins[func](env, av);
		close(env->pipe_fd[1]);
		env->pipe_fdin = env->pipe_fd[0];
	}
}
