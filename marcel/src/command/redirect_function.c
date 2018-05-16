/*
** EPITECH PROJECT, 2018
** redirect_function
** File description:
** minishell2
*/

#include "minishell2.h"

static int simple_left(mysh_t *mysh, int nb)
{
	int fd;

	if (mysh->file[1] == NULL) {
		fd = open(mysh->file[0], O_RDONLY);
		if (fd < 0) {
			my_putstr(mysh->file[0]);
			my_putstr(": No such file or directory.\n");
			mysh->ex_val = 1;
			close(fd);
			return (nb);
		}
		close(fd);
	}
	return (nb);
}

static int simple_right_2(mysh_t *mysh, int nb, int fd)
{
	int newfd;

	for (int i = 1; i < mysh->nb_file; i++) {
		newfd = open(mysh->file[i], O_RDONLY);
		if (newfd <= 0) {
			my_putstr(mysh->arg[0]);
			my_putstr(": cannot access '");
			my_putstr(mysh->file[i]);
			my_putstr("': No such file or directory\n");
			mysh->ex_val = 2;
		} else {
			write(fd, mysh->file[i],
			my_strlen(mysh->file[i]));
			write(fd, "\n", 1);
			close(newfd);
		}
	}
	close(fd);
	return (nb);
}

static int double_right(mysh_t *mysh, int nb)
{
	int fd;
	int fd2 = 3;
	int fd3 = 4;

	fd = open(mysh->file[0], O_CREAT
	| O_RDWR | O_APPEND, 0644);
	if (mysh->file[1] == NULL) {
		fd2 = dup(1);
		close(1);
		fd3 = dup(fd);
		nb = call_function(mysh, nb);
		close(fd);
		close(1);
		fd3 = dup(fd2);
		close(fd2);
	}
	return (nb);
}

static int simple_right(mysh_t *mysh, int nb)
{
	int fd;
	int fd2 = 3;
	int fd3 = 4;

	fd = open(mysh->file[0], O_CREAT
	| O_RDWR | O_TRUNC, 0644);
	if (mysh->file[1] == NULL) {
		fd2 = dup(1);
		close(1);
		fd3 = dup(fd);
		nb = call_function(mysh, nb);
		close(fd);
		close(1);
		fd3 = dup(fd2);
		close(fd2);
	} else
		simple_right_2(mysh, nb, fd);
	return (nb);
}

int redirect_function(mysh_t *mysh, int nb)
{
	if (mysh->redirect == 1)
		nb = simple_right(mysh, nb);
	else if (mysh->redirect == 3)
		nb = double_right(mysh, nb);
	if (mysh->redirect == 2)
		nb = simple_left(mysh, nb);
	return (nb);
}
