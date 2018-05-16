/*
** EPITECH PROJECT, 2018
** chdir
** File description:
** minishell
*/

#include "minishell.h"

void update_env_pwd(env_t *env, char *cwd)
{
	listenv_t *listenv_tmp = env->listenv;

	while (listenv_tmp) {
		if (my_strncmp(listenv_tmp->line, S_PWD, 3) == 0)
			break;
		listenv_tmp = listenv_tmp->next;
	}
	if (listenv_tmp) {
		my_setenv(env, "OLDPWD", &listenv_tmp->line[4],
			name_exist(env, "OLDPWD"));
		env->pwdold_path = NULL;
		env->pwdold_path = &listenv_tmp->line[4];
	}
	my_setenv(env, "PWD", cwd, name_exist(env, "PWD"));
	env->pwd_path = my_strcat_malloc(NULL, cwd);
}

int my_cd_prev(env_t *env)
{
	int ret_ch = 0;
	char cwd[256];

	ret_ch = chdir(env->pwdold_path);
	getcwd(cwd, sizeof(cwd));
	update_env_pwd(env, cwd);
	write(1, cwd, my_strlen(cwd));
	my_putchar('\n');
	if (ret_ch != 0) {
		env->exit_code = 1;
		perror(env->pwdold_path);
		return -1;
	}
	return 0;
}

int my_cd_root(env_t *env)
{
	int ret_ch = 0;
	char *root = my_strcat_malloc("/home/", env->usr_name);
	char cwd[256];

	ret_ch = chdir(root);
	getcwd(cwd, sizeof(cwd));
	update_env_pwd(env, cwd);
	free(root);
	return ret_ch;
}

int error_handler(char **cd_arg, int ret_ch, env_t *env)
{
	int len = my_array_size(cd_arg);

	if (ret_ch == 0)
		return 1;
	if (ret_ch != 0) {
		cd_err((len == 2) ? cd_arg[1] : "~");
		env->exit_code = 1;
		return -1;
	}
	return 1;
}

int my_cd(char **cd_arg, env_t *env)
{
	int ret_ch = 0;
	char cwd[256];

	if (my_strcmp(cd_arg[1], "-") == 0)
		ret_ch = my_cd_prev(env);
	else if (my_array_size(cd_arg) == 1
	|| my_strcmp(cd_arg[1], "~") == 0)
		ret_ch = my_cd_root(env);
	else {
		ret_ch = chdir(cd_arg[1]);
		getcwd(cwd, sizeof(cwd));
		update_env_pwd(env, cwd);
	}
	return error_handler(cd_arg, ret_ch, env);
}
