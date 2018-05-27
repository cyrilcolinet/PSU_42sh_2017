/*
** EPITECH PROJECT, 2018
** my_exec
** File description:
** 42
*/

# include "shell.h"

static int	get_redirection_type(char *av, int *canal)
{
	redirection_t	arr[] = {
		{">", 1}, {">>", 2}, {"2>", 1}, {"2>>", 2}, {">&2", 1},
		{NULL, 0}
	};

	for (int k = 0; arr[k].string != NULL; k++) {
		if (!my_strequ(av, arr[k].string))
			continue;
		if (av[0] == 2)
			*canal = 2;
		return arr[k].type;
	}
	return -1;
}

static int	is_right_redir(char **av, int *canal)
{
	int		i = 0;
	int		return_value;

	while (av && av[i]) {
		return_value = get_redirection_type(av[i], canal);
		if (return_value != -1)
			return  return_value;
		i++;
	}
	return -1;
}

static int	perform_right_redir(char **av, int type, int canal_value)
{
	int	i = 0;
	int	fd;
	int	flags;

	while (av && av[i]) {
		if (av[i][(type == 1) ? 0 : 1] == '>' || av[i][0] == '2')
			break;
		i++;
	}
	if (i + 1 > my_array_size(av))
		return 0;
	flags = type == 1 ? O_CREAT | O_WRONLY : O_CREAT | O_WRONLY | O_APPEND;
	fd = open(av[i + 1], flags, 0666);
	while (av[i]) {
		av[i] = 0;
		i++;
	}
	close(canal_value);
	dup2(fd, canal_value);
	return fd;
}

void	right_redirection(char *bin_cmd, char **av, int *fd_flag)
{
	int	type = 0;
	int	flag;
	int	canal_value = 1;

	if ((type = is_right_redir(av, &canal_value)) == -1)
		return;
	flag = perform_right_redir(av, type, canal_value);
	*fd_flag = flag;
	(void)bin_cmd;
}
