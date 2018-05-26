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
	if (ret < 0)
		exec_err(bin_cmd, env);
}

int exec_prog(char **av, env_t *env, int cmd_access)
{
	pid_t pid;
	char *bin_cmd = NULL;
	int redir = 0;

	env->str_env = my_list_to_array(env);
	bin_cmd = get_path(env, av[0], &cmd_access);
	if (bin_cmd == NULL)
		return -1;
	pid = fork();
	if (pid == 0)
		exec_child(bin_cmd, av, &redir, env);
	else
		wstatus_handler(pid, env);
	free_protect(bin_cmd, env, cmd_access);
	if (redir != 0)
		close(redir);
	return 0;
}

void exec_cmdline(char *line, env_t *env, parser_t *parser)
{
	char **av = my_str_to_array_42(line, ' ');
	int func_built = -1;
	int cmd_access = 0;

	if (av[0] == NULL || is_a_variable_assign(av, env) == 1) {
		free(av);
		return;
	}
	av = apply_alias(av, env);
	av = apply_local_variables(av, env);
	func_built = is_builtin(av[0]);
	if (func_built >= 0)
		call_builtins(func_built, av, env, parser);
	else {
		exec_prog(av, env, cmd_access);
	}
	my_freetab(av);
}
