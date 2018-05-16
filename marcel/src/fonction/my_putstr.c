/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** task02D03
*/

#include "minishell2.h"

void my_putstr(char *str)
{
	if (str != NULL) {
		for (int i = 0; str[i] != '\0'; i++) {
			my_putchar(str[i]);
		}
	}
}
