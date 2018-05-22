/*
** EPITECH PROJECT, 2018
** 42
** File description:
** include
*/

# ifndef READ_SIZE
# define READ_SIZE (100)
# endif

# ifndef SHELL_H
# define SHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <signal.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <ncurses.h>
# include <pthread.h>
# include "globbing.h"
# include "my.h"

# define EXIT_SUCCESS 0

# define S_PWD "PWD="
# define S_USR "USER="
# define S_BINPATH "PATH="
# define S_OLDPWD "OLDPWD="
#define S_HOME "HOME="

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

typedef struct hist_s {
	char 		*cmd;
	struct hist_s	*next;
} hist_t;

typedef struct listenv_s {
	char *line;
	struct listenv_s *next;
} listenv_t;

typedef struct syspath_s {
	char *path;
	struct syspath_s *next;
} syspath_t;

typedef struct shell_var_s {
	char			*var_name;
	char			*var_value;
	struct shell_var_s	*next;
} shell_var_t;

typedef struct shell_alias_s {
	char			*alias_name;
	char			*alias_cmd;
	struct shell_alias_s	*next;
} shell_alias_t;

typedef struct env_s {
	listenv_t	*listenv;
	char		**str_env;
	char		*usr_name;
	syspath_t	*syspath;
	char		*pwd_path;
	char		*pwdold_path;
	int		exit_code;
	hist_t		*history;
	char		*bashrc_path;
	shell_var_t	*shell_var;
	shell_alias_t	*shell_alias;
} env_t;

int is_builtin(char *str);
void call_builtins(int func, char **av, env_t *env);
void exec_btree(char *, env_t *);

/* ENV */

listenv_t *init_listenv(char **av_env);
syspath_t *init_syspath(char *syspath);
env_t init_env(char **);
int name_exist(env_t *env, char *name);
int my_unsetenv(env_t *env, char *name);
int my_setenv(env_t *env, char *name, char *value, int overwrite);
void my_env(env_t *env, char **av);
int add_env(env_t *env, char *name, char *value);
int change_env(env_t *env, char *name, char *value);
int posix_bug(char *, env_t *);
char *get_env_var(char **av_env, char *var_cmp, int size);
void add_line(listenv_t **list, char *line);
void free_listenv(env_t *);
void my_setenv_cmd(env_t *env, char **av);
void my_unsetenv_cmd(env_t *env, char **av);
void free_syspath(env_t *);
void free_env(env_t *env);
void update_path(env_t *env);
void update_env(env_t *env);

/* CD */

void my_cd(env_t *, char **);
int is_file(char *);

/* EXEC */

int exec_prog(char **av, env_t *env, int cmd_access);
char *get_path(env_t *env, char *cmd, int *cmd_access);
void exec_cmdline(char *line, env_t *env);

/* EXIT */

void exit_success(env_t *, char **);

/* ECHO */
void my_echo(env_t *, char **);

/* PARSER */

char *clear_str(char *);
char *clear_begin(char *);
char *clear_end(char *);
char *clear_space(char *, int);
char *clear_separator(char *);
char *clear_semicolon(char *);
char *clear_begin_semicolon(char *);
char *clear_end_semicolon(char *);
char *clear_pipe(char *);
char *clear_dpipe(char *);
char *clear_ampersand(char *);
char *clear_dampersand(char *);
char *clear_redirect_right(char *);
char *clear_redirect_left(char *);
char *clear_redirect_dleft(char *);
char *clear_redirect_dright(char *);
char **my_str_to_array_42(char *, char);
char **my_str_to_array_pipe_42(char *);

parser_t *parser(char*);
p_pipe_t *get_pipe_in_cmd(parser_t **, char *);

/* ERROR MANAGMENT */

bool error_management(char *, env_t *);

/* HISTORY */

void free_history(env_t *);
void fill_history(env_t *, char *);

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

int exec_err(char *, pid_t);
void cd_err(char *);
void print_status(int);
void wstatus_handler(int , char *, pid_t , env_t *);

/* UTILS */

int my_list_size(env_t *);
int is_alone(char *);
char **my_list_to_array(env_t *);
char *get_next_line(int);

/* INHIBITORS */
void	apply_inhibitors(parser_t **);
void	change_cmd_inhibitors(parser_t **, char *);
void	error_remove_inhibitor(char *, parser_t **);
int	error_inhibitor(char *);

/* ALIAS */
char	**apply_alias(char **, env_t *);
char	*is_cmd_alias(char *, char *, env_t *);
char	*search_alias(char *, env_t *);
char	*get_alias_cmd(char *);
void	my_alias(env_t *, char **);
void	print_alias(env_t *);
char	*search_shell_alias(env_t *, char *);

/* VARIABLES */
char	*get_variable_value(char *);
char	*get_variable_name(char *);
int	valid_variable(char *);
int	is_a_variable_assign(char *, env_t *);
void	add_variable_in_shell(env_t *, char *);
char	*find_variable(env_t *, char *);
void	apply_local_variables(char ***, env_t *);

/* CTRL CATCHER */
#define ctrl(x) ((x) & 0x1f)

void	ctrl_catcher(char);

#endif
