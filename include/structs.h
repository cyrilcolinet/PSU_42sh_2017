/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** structs header file
*/

# ifndef STRUCTS_SHELL_H
# define STRUCTS_SHELL_H

# include <termios.h>

typedef struct {
	char			*string;
	int			type;
} redirection_t;

typedef struct p_pipe_s {
	char			*pipe_cmd;
	struct p_pipe_s 	*next;
} p_pipe_t;

typedef struct parser_s {
	char			*full_cmd;
	p_pipe_t		*pipe_in_cmd;
	struct parser_s		*next;
} parser_t;

typedef struct hist_s {
	char 			*cmd;
	struct hist_s		*next;
} hist_t;

typedef struct listenv_s {
	char 			*var;
	char 			*content;
	struct listenv_s 	*next;
} listenv_t;

typedef struct syspath_s {
	char 			*path;
	struct syspath_s	*next;
} syspath_t;

typedef struct shell_var_s {
	char			*var_name;
	char			*var_value;
	struct shell_var_s *next;
} shell_var_t;

typedef struct shell_alias_s {
	char			*alias_name;
	char			*alias_cmd;
	struct shell_alias_s *next;
} shell_alias_t;

typedef struct proc_s {
	char 			**cmd;
	pid_t 			pid;
	bool 			complete;
	bool			stopped;
	int			status;
	struct proc_s		*next;
}	proc_t;

typedef struct job_s {
	int 			bg;
	char 			**cmd;
	pid_t 			pid;
	proc_t			parent;
	struct termios		save;
	int 			fds[3];
	struct job_s 		*next;
}	job_t;

typedef struct commons_s {

}	commons_t;

typedef struct ncurses_s {
	bool			active;
	char 			**keymap;
	commons_t		*commons;
}	ncurses_t;

typedef struct env_s {
	listenv_t		*listenv;
	char			**str_env;
	char			*usr_name;
	syspath_t		*syspath;
	char			*pwd_path;
	int			exit_code;
	int			pipe_fd[2];
	int			pipe_next;
	int			pipe_fdin;
	hist_t			*history;
	char			*bashrc_path;
	char 			**keymap;
	shell_var_t		*shell_var;
	shell_alias_t		*shell_alias;
	char			**line_sep;
	char			**line;
	ncurses_t 		*ncs;
} env_t;

# endif
