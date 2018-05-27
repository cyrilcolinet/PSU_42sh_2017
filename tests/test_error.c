/*
** EPITECH PROJECT, 2018
** test
** File description:
** criterion
*/

#include <criterion/criterion.h>
# include "shell.h"

Test(print_error, test0)
{
	int i = 0;

	while (i < 32) {
		print_status(i);
		i++;
	}
}
