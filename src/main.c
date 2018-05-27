/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** main function
*/

# include "shell.h"

int main(int ac, char **av, char **env)
{
	int res = 0;
	(void)ac;
	(void)av;

	if (*env == NULL) {
		write(2, "Environment is null.\n", 21);
		return (84);
	}

	res = main_shell(env);
	return (res);
}
