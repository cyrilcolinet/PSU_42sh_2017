/*
** EPITECH PROJECT, 2018
** alone
** File description:
** 42
*/

int is_alone(char *syspath)
{
	int i = 0;

	while (syspath && syspath[i]) {
		if (syspath[i] == ':')
			return 1;
		i++;
	}
	return 0;
}
