/*
** EPITECH PROJECT, 2018
** chdir
** File description:
** 42
*/

# include "42.h"

static void update_env_pwd(env_t *env, char *cwd)
{
	char *current_pwd = env_get_variable(S_PWD, env);

	my_setenv(env, "OLDPWD", current_pwd, 0);
	my_setenv(env, "PWD", cwd, 0);
	env->pwd_path = my_strcat_malloc(NULL, cwd);
}

static int my_cd_prev(env_t *env)
{
	int ret_ch = 0;
	char *path = env_get_variable(S_OLDPWD, env);

	ret_ch = chdir(path);
	if (ret_ch != 0) {
		env->exit_code = 1;
		perror(path);
		return -1;
	}
	return 0;
}

static int my_cd_root(env_t *env)
{
	int ret_ch = 0;
	char *root = env_get_variable(S_HOME, env);
	char cwd[256];

	ret_ch = chdir(root);
	getcwd(cwd, sizeof(cwd));
	update_env_pwd(env, cwd);
	return ret_ch;
}

static int error_handler(char **cd_arg, int ret_ch, env_t *env)
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

void my_cd(env_t *env, char **cd_arg)
{
	int ret_ch = 0;
	char cwd[256];

	if (my_array_size(cd_arg) > 1 && my_strcmp(cd_arg[1], "-") == 0)
		ret_ch = my_cd_prev(env);
	else if (my_array_size(cd_arg) == 1
	|| my_strcmp(cd_arg[1], "~") == 0)
		ret_ch = my_cd_root(env);
	else {
		ret_ch = chdir(cd_arg[1]);
		getcwd(cwd, sizeof(cwd));
		update_env_pwd(env, cwd);
	}
	error_handler(cd_arg, ret_ch, env);
}
