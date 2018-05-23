/*
** EPITECH PROJECT, 2018
** my_exec
** File description:
** 42
*/

#include <glob.h>
#include "42.h"

static void free_protect(char *bin_cmd, env_t *env, int cmd_access)
{
	//if (env->str_env)
	//	my_freetab(env->str_env);
	if (cmd_access == 1)
		return;
	if (bin_cmd)
		free(bin_cmd);
	free_list_to_str(env);
}

static void exec_child(char *bin_cmd, char **av, int *redir, env_t *env)
{
	int	ret = 0;

	av = apply_globbing(av);
	right_redirection(bin_cmd, av, redir);
	left_redirection(bin_cmd, av, redir);
	ret = execve(bin_cmd, av, env->str_env);
	if (ret == -1)
		exec_err(bin_cmd, getpid());
}

int exec_prog(char **av, env_t *env, int cmd_access)
{
	pid_t pid;
	int status = 0;
	char *bin_cmd = NULL;
	int redir = 0;

	env->str_env = my_list_to_array(env);
	bin_cmd = get_path(env, av[0], &cmd_access);
	if (bin_cmd == NULL)
		return -1;
	pid = fork();
	if (pid == 0) {
		exec_child(bin_cmd, av, &redir, env);
	} else {
		waitpid(pid, &status, WUNTRACED | WCONTINUED);
		wstatus_handler(status, bin_cmd, getpid(), env);
	}
	free_protect(bin_cmd, env, cmd_access);
	if (redir != 0)
		close(redir);
	return 0;
}

void exec_cmdline(char *line, env_t *env)
{
	char **av = my_str_to_array_42(line, ' ');
	int func_built = -1;
	int cmd_access = 0;

	if (av[0] == NULL || is_a_variable_assign(av, env) == 1) {
		free(av);
		return;
	}
	av = apply_alias(av, env);
	apply_local_variables(&av, env);
	func_built = is_builtin(av[0]);
	if (func_built >= 0)
		call_builtins(func_built, av, env);
	else {
		env->exit_code = 0;
		exec_prog(av, env, cmd_access);
	}
	my_freetab(av);
}
