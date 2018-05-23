/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** job_control functions (header file)
*/

# ifndef SHELL_JOBS_H
# define SHELL_JOBS_H

# include <sys/types.h>
# include <termios.h>

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

# endif
