/*
** EPITECH PROJECT, 2017
** my_str_isalpha
** File description:
** task10
*/

int my_str_isalpha(char *str)
{
	int i = 0;

	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0') {
		if (str[i] < 65)
			return (0);
		i++;
	}
	return (1);
}
