/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** task05D04
*/

#include "minishell2.h"

int my_getnbr(char *str)
{
	int i = 0;
	int j = 1;
	int nb = 0;

	while ((str[i] < '0' || str[i] > '9') &&
	str[i] != '\0') {
		if (str[i] == '-') {
			j = j * -1;
		}
		i = i + 1;
	}
	while (str[i] != '\0') {
		while ((str[i] >= '0' && str[i] <= '9')) {
			nb = nb * 10;
			nb = nb + str[i] - '0';
			i = i + 1;
		}
		return (nb * j);
	}
	return (nb * j);
}
