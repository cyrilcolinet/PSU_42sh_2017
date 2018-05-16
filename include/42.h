/*
** EPITECH PROJECT, 2018
** 42
** File description:
** include
*/

#ifndef READ_SIZE
#define READ_SIZE (100)
#endif

#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

#define EXIT_SUCCESS 0

#define S_PWD "PWD="
#define S_USR "USER="
#define S_BINPATH "PATH="
#define S_OLDPWD "OLDPWD="

typedef struct {
	char	*string;
	int	type;
} redirection_t;

typedef struct p_pipe_s {
	char		*pipe_cmd;
	struct p_pipe_s *next;
} p_pipe_t;

typedef struct parser_s {
	char		*full_cmd;
	p_pipe_t	*pipe_in_cmd;
	struct parser_s	*next;
} parser_t;

typedef struct listenv_s {
	char *line;
	struct listenv_s *next;
} listenv_t;

typedef struct syspath_s {
	char *path;
	struct syspath_s *next;
} syspath_t;

typedef struct env_s {
	listenv_t *listenv;
	char **str_env;
	char *usr_name;
	syspath_t *syspath;
	char *pwd_path;
	char *pwdold_path;
	int exit_code;
} env_t;

void call_builtins(int func, char **av, env_t *env);
int is_builtin(char *str, char **builtins);
void exec_btree(char *, env_t *);

/* ENV */

char *get_env_var(char **av_env, char *var_cmp, int size);
int name_exist(env_t *env, char *name);
void add_line(listenv_t **list, char *line);
listenv_t *init_listenv(char **av_env);
void free_listenv(env_t *);
env_t init_env(char **);
int my_unsetenv(env_t *env, char *name);
int my_setenv(env_t *env, char *name, char *value, int overwrite);
int my_env(env_t *env);
void my_setenv_cmd(env_t *env, char **av);
void my_unsetenv_cmd(env_t *env, char **av);
int add_env(env_t *env, char *name, char *value);
int change_env(env_t *env, char *name, char *value);
void free_syspath(env_t *);
syspath_t *init_syspath(char *syspath);
void free_env(env_t *env);
int posix_bug(char *, env_t *);
void update_path(env_t *env);
void update_env(env_t *env);

/* CD */

int my_cd(char **cd_arg, env_t *env);
int is_file(char *);

/* EXEC */

int exec_prog(char **av, env_t *env, int cmd_access);
char *get_path(env_t *env, char *cmd, int *cmd_access);
void exec_cmdline(char *line, env_t *env);

/* EXIT */

void exit_success(char **, env_t *);

/* PARSER */

parser_t *parser(char*);
p_pipe_t *get_pipe_in_cmd(parser_t **, char *);

/* PROMPT */

char *get_cdir(env_t);
void prompt(env_t);

/* REDIRECTION */

void right_redirection(char *, char **, int *);
void left_redirection(char *, char **, int *);

/* PIPE */

void exec_pipe(char **, int *, env_t *, int);
void exec_all_pipe(p_pipe_t *, env_t *);

/* SIG */

void cd_err(char *);
int exec_err(char *, pid_t);
void print_status(int);
void wstatus_handler(int , char *, pid_t , env_t *);

/* UTILS */

char *clear_str(char *);
char *clear_space(char *);
int my_list_size(env_t *);
char **my_list_to_array(env_t *);
int is_alone(char *);
char *my_strconfigure(unsigned int );
char *get_next_line(int);

#endif
