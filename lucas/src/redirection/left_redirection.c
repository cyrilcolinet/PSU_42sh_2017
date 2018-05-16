/*
** EPITECH PROJECT, 2018
** my_exec
** File description:
** minishell
*/

#include "minishell.h"

int		is_left_redir(char **av)
{
	int	i = 0;

	while (av && av[i]) {
		if (my_strcmp(av[i], "<") == 0)
			return 1;
		if (my_strcmp(av[i], "<<") == 0)
			return 2;
		i++;
	}
	return -1;
}

int		perform_left_redir(char **av, int type)
{
	int		i = 0;
	int		fd;

	while (av && av[i]) {
		if (av[i][(type == 1) ? 0 : 1] == '<')
			break;
		i++;
	}
	if (i + 1 > my_array_size(av))
		return 0;
	fd = open(av[i + 1], O_RDONLY);
	while (av[i]) {
		av[i] = 0;
		i++;
	}
	close(0);
	dup2(fd, 0);
	return fd;
}

void		left_redirection(char *bin_cmd, char **av, int *fd_flag)
{
	int	type = 0;
	int	flag;

	if ((type = is_left_redir(av)) == -1)
		return;
	flag = perform_left_redir(av, type);
	*fd_flag = flag;
	(void)bin_cmd;
}
