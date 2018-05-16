/*
** EPITECH PROJECT, 2018
** my_memset
** File description:
** lib
*/

void my_memset(char *buffer, int size)
{
	int i = 0;

	while (i < size) {
		buffer[i] = '\0';
		i++;
	}
}
