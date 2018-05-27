/*
** EPITECH PROJECT, 2018
** PSU_4ésh_2017
** File description:
** 42sh functions (header file)
*/

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
# include <curses.h>
# include <term.h>
# include <pthread.h>
# include <sys/ioctl.h>
# include <errno.h>
# include <glob.h>
# include <termios.h>

# include "my.h"

# define S_PWD 		("PWD")
# define S_USR 		("USER")
# define S_BINPATH 	("PATH")
# define S_OLDPWD 	("OLDPWD")
# define S_HOME 	("HOME")

typedef struct {
	char		*string;
	int		type;
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
	char 		*var;
	char 		*content;
	struct listenv_s *next;
} listenv_t;

typedef struct syspath_s {
	char 		*path;
	struct syspath_s *next;
} syspath_t;

typedef struct shell_var_s {
	char		*var_name;
	char		*var_value;
	struct shell_var_s *next;
} shell_var_t;

typedef struct shell_alias_s {
	char		*alias_name;
	char		*alias_cmd;
	struct shell_alias_s *next;
} shell_alias_t;

typedef struct proc_s {
	char 		**cmd;
	pid_t 		pid;
	bool 		complete;
	bool		stopped;
	int		status;
	struct proc_s	*next;
}	proc_t;

typedef struct job_s {
	int 		bg;
	char 		**cmd;
	pid_t 		pid;
	proc_t		parent;
	struct termios	save;
	int 		fds[3];
	struct job_s 	*next;
}	job_t;

typedef struct env_s {
	listenv_t	*listenv;
	char		**str_env;
	char		*usr_name;
	syspath_t	*syspath;
	char		*pwd_path;
	int		exit_code;
	hist_t		*history;
	char		*bashrc_path;
	char 		**keymap;
	shell_var_t	*shell_var;
	shell_alias_t	*shell_alias;
	char		**line_sep;
	char		**line;
} env_t;

int 		is_builtin(char *);
void 		call_builtins(int, char **, env_t *, parser_t *);
void 		exec_btree(char *, env_t *);
int 		main_shell(char **);

/*
** Environment
** Parse environment in linked list
** Structs: listenv_t, syspath_t, env_t
*/
listenv_t 	*init_listenv(char **);
listenv_t 	*new_environment_entry(char *, char*, listenv_t *);
syspath_t 	*init_syspath(char *);

char 		*env_get_variable(char *, env_t *);
env_t 		init_env(char **);
int 		name_exist(env_t *, char *);
int 		my_unsetenv(env_t *, char *);
int 		my_setenv(env_t *, char *, char *, int);
void 		my_env(env_t *, char **);
int 		change_env(env_t *, char *, char *);
int 		posix_bug(char *, env_t *);
void 		free_listenv(env_t *);
void 		my_setenv_cmd(env_t *, char **);
void 		my_unsetenv_cmd(env_t *, char **);
void 		free_syspath(env_t *);
void 		free_env(env_t *);
void 		update_path(env_t *);
void 		update_env(env_t *);

/*
** Cd builtin
** Change directory
** Structs: env_t
*/
void 		my_cd(env_t *, char **);
int 		is_file(char *);

/*
** Execution
** Execute process with execve
** Struct: parser_t
*/
int 		exec_prog(char **, env_t *, int);
char 		*get_path(env_t *, char *, int *);
void 		exec_cmdline(char *, env_t *, parser_t *);

/*
** Exit builtin
** Exit program when exit command typed
** Structs: env_t, parser_t
*/
void 		exit_success(env_t *, char **, parser_t *);

/*
** Echo command builtin
** Print content in stdout
** Structs: env_get_variable*/
void 		my_echo(env_t *, char **);

/*
** Parsing functions
** Parse command in binary tree and error management
** Structs: parser_t, p_pipe_t
*/
char 		*clear_str(char *);
char 		*clear_begin(char *);
char 		*clear_end(char *);
char 		*clear_space(char *, int);
char 		*clear_separator(char *);
char 		*clear_semicolon(char *);
char 		*clear_begin_semicolon(char *);
char 		*clear_end_semicolon(char *);
char 		*clear_pipe(char *);
char 		*clear_dpipe(char *);
char 		*clear_ampersand(char *);
char 		*clear_dampersand(char *);
char 		*clear_redirect_right(char *);
char 		*clear_redirect_left(char *);
char 		*clear_redirect_dleft(char *);
char 		*clear_redirect_dright(char *);
char 		**my_str_to_array_42(char *, char);
char 		**my_str_to_array_pipe_42(char *);
char		**str_to_tab_separator(char *);
char		**split_line_separator(char *);
int		check_next_separator(char **, int);

parser_t 	*parser(char *);
p_pipe_t 	*get_pipe_in_cmd(parser_t **, char *);
void		free_struct_parser(parser_t *);

/*
** Error handling
** Manage errors (parsing, and other)
*/
bool 		error_management(char *);

/*
** History
** Manage history (add command in .42sh_history file)
** Structs: hist_t, env_t
*/
void 		free_history(env_t *);
void 		fill_history(env_t *, char *);

/*
** Prompt
** Display prompt with env variables and more
** Structs: env_t
*/
char 		*get_cdir(env_t);
void 		prompt(env_t);

/*
** Redirections
** Manage left and right redirections (simple and double)
** Structs: env_t
*/
void 		right_redirection(char *, char **, int *);
void 		left_redirection(char *, char **, int *);

/*
** Pipes
** Pipe management
** Structs: env_t, p_pipe_t
*/
void 		exec_pipe(char **, int *, env_t *, int);
void 		exec_all_pipe(p_pipe_t *, env_t *);

/*
** Signal handling
** Signal catcher (segfault and more)
** Structs: env_t
*/
int 		exec_err(char *, env_t *);
void 		cd_err(char *);
void 		print_status(int, int);
void 		wstatus_handler(pid_t , env_t *);

/*
** Utilities
** Convert listenv_t in char ** for execve
** get_next_line, realloc, join_characters and more...
** Structs: env_t
*/
int 		my_list_size(env_t *);
int 		is_alone(char *);
char 		**my_list_to_array(env_t *);
char 		*get_next_line(int);
void 		free_list_to_str(env_t *);
char 		*replace_char(char *, char, char);
char 		*path_join(char *, char *);
char 		*join_next_values(char **);
char 		*realloc_char(char *, unsigned int);

/*
** Inhibitors (League of Legends)
** Apply inhibitors in btree_t
** Structs: env_t, parser_t, btree_t
*/
void		apply_inhibitors(parser_t **);
void		change_cmd_inhibitors(parser_t **, char *);
void		error_remove_inhibitor(char *, parser_t **);
int		error_inhibitor(char *);

/*
** Aliases
** Apply aliases in btree_t
** Structs: btree_t, env_t
*/
char		**apply_alias(char **, env_t *);
char		*is_cmd_alias(char *, char *, env_t *);
char		*search_alias(char *, env_t *);
char		*get_alias_cmd(char *);
void		my_alias(env_t *, char **);
void		print_alias(env_t *);
char		*search_shell_alias(env_t *, char *);
void		free_shell_alias(env_t *);

/*
** Local variables
** Manage local variables
** TODO: Fix and correct errors and add unset command
** Structs: env_t
*/
char		*get_variable_value(char *);
char		*get_variable_name(char *);
int		valid_variable(char **);
int		is_a_variable_assign(char **, env_t *);
void		add_variable_in_shell(env_t *, char **);
char		*find_variable(env_t *, char *);
char		**apply_local_variables(char **, env_t *);
void 		del_variable_in_shell(env_t *, char **);
void		free_shell_variables(env_t *);

/*
** Globbings
** Apply globbings
** Structs: env_t
*/
char		is_globbing(char *);
char		**apply_globbing(char **);
int		globbing_in_cmd(char *);

/*
** Key mapping and key catcher
** Get keys typed in terminal with help of termios
** Structs: env_t
*/
bool		load_keys(env_t *);
bool		can_apply_keybinding(env_t *);

# endif
