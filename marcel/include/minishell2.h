/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** header minishell2
*/

#ifndef READ_SIZE
#define READ_SIZE (100)
#endif

#ifndef MINISHELL2_H
#define MINISHELL2_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdbool.h>

typedef struct stat stat_t;

typedef struct mysh {
	char ***all_arg;
	char ***pipe_arg;
	char **arg;
	char **file;
	char **env;
	char **path;
	char *home;
	char *name;
	char *value;
	char *hist;
	bool state;
	bool redi;
	int redirect;
	int nb_all_arg;
	int nb_arg;
	int nb_pipe;
	int nb_file;
	int fdout;
	int next;
	int ex_val;
	int histnb;
	int save;
	int overwrite;
} mysh_t;

int minishell(int ac, char **av, char **env);
void boucle(int nb, mysh_t *mysh, char *s);

bool my_get_all_arg(mysh_t *mysh, char *s);
void my_get_current_arg(mysh_t *mysh, int x);
void my_get_current_pipe_arg(mysh_t *mysh, int x);
void redirect_get_args(mysh_t *mysh, char *s);
bool check_pipe_error(mysh_t *mysh, char *s);
bool check_redirect_error(mysh_t *mysh, char *s);
void just_copy_all_arg(mysh_t *mysh, int x);
void get_type_redirect(mysh_t *mysh, char *s);

char **copy_path(mysh_t *mysh);
char **copy_env(char **env);
char *copy_home(mysh_t *mysh);
char **add_env(mysh_t *mysh);
void check_env(mysh_t *mysh);
void print_env(mysh_t *mysh);
void call_setenv(mysh_t *mysh);
void call_unsetenv(mysh_t *mysh);
int my_setenv(mysh_t *mysh);
int my_unsetenv(mysh_t *mysh);

char **check_is_a_file(char *str, mysh_t *mysh);
int check_tiret(mysh_t *mysh);
int check_wave(mysh_t *mysh);
void call_cd(mysh_t *mysh);
void get_new_hist(mysh_t *mysh);

int check_exit(mysh_t *mysh);
int exit_fonction(mysh_t *mysh);

void command(mysh_t *mysh);
int call_function(mysh_t *mysh, int nb);
int call_redirect(mysh_t *mysh, int nb);
void execution_command(mysh_t *mysh, char *name);
void handler_int(int sig);
bool echo_ex_val(mysh_t *mysh);
bool is_dir(mysh_t *mysh, char *name);
int redirect_function(mysh_t *mysh, int nb);

char *my_strconfigure(unsigned int size);
char *clear_str(char *s);
char *clear_space(char *s);
char *get_next_line(int fd);
void my_putchar(char c);
void my_putstr(char *str);
int my_strlen(char *str);
int my_getnbr(char *str);
char *my_strdup(char *str);
void my_put_nbr(int n);
void my_freetab(char **arr);

#endif
