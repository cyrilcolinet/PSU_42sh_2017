/*
** EPITECH PROJECT, 2018
** clear_str
** File description:
** minishell2
*/

#include "minishell2.h"

static char *change_tab_space(char *s)
{
	if (s == NULL)
		return (NULL);
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == '\t')
			s[i] = ' ';
	}
	return (s);
}

static char *clear_beg(char *s)
{
	char *str;
	int nb = 0;
	int j = 0;
	int k = 0;

	if (s == NULL)
		return (NULL);
	if (s[0] == ' ')
		while (s[k] == ' ') {
			k++;
			nb++;
		}
	str = malloc(sizeof(char) * (my_strlen(s) - nb + 1));
	for (int i = nb; s[i] != '\0'; i++) {
		str[j] = s[i];
		j++;
	}
	str[my_strlen(s) - nb] = '\0';
	free(s);
	return (str);
}

static char *clear_end2(char *s, int nb)
{
	int len = 0;
	char *str;

	len = my_strlen(s) - nb;
	str = malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++)
		str[i] = s[i];
	str[len] = '\0';
	free(s);
	return (str);
}

static char *clear_end(char *s)
{
	int nb = 0;
	int k = 0;

	if (s == NULL)
		return (NULL);
	for (int i = nb; s[i] != '\0'; i++) {
		if (s[i] == ' ') {
			k = i;
			while (s[k] == ' ') {
				nb++;
				k++;
			}
			if (s[k] == '\0') {
				s = clear_end2(s, nb);
				return (s);
			}
		}
		nb = 0;
	}
	return (s);
}

char *clear_str(char *s)
{
	s = change_tab_space(s);
	s = clear_beg(s);
	s = clear_end(s);
	s = clear_space(s);
	return (s);
}
