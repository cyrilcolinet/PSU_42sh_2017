/*
** EPITECH PROJECT, 2018
** str_to_tab_separator
** File description:
** 42
*/

# include "shell.h"

static int pass_quote(char *str, int i, char delim)
{
	i++;
	while (str[i] != delim)
		i++;
	return (i);
}

static int str_to_array_count_words(char *str, int count)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == 39) {
			i = pass_quote(str, i, 39);
			continue;
		}
		if (str[i] == 34) {
			i = pass_quote(str, i, 34);
			continue;
		}
		if (str[i] != '\0' && str[i + 1] == '|'
		&& str[i + 1] != '\0' && str[i + 1] == '|'
		&& str[i + 2] != '\0' && str[i + 2] == ' ')
			count++;
	}
	return (count);
}

static int get_len(char *str, int i)
{
	int len = 0;
	int quote = 1;
	int dquote = 1;

	for (; str[i] != '\0'; i++) {
		if (str[i] == 34)
			dquote *= -1;
		if (str[i] == 39)
			quote *= -1;
		if (quote == 1 && dquote == 1 && (str[i] == '|'
		&& str[i + 1] != '\0' && str[i + 1] == '|'))
			break;
		len++;
	}
	return (len);
}

static char **get_the_array(char *str, int count)
{
	char **new = malloc(sizeof(char *) * (count + 1));
	int len = 0;
	int a = 0;
	int i = 0;

	if (new == NULL)
		return (NULL);
	for (a = 0; str[i] != '\0'; a++) {
		len = get_len(str, i);
		new[a] = my_strconfigure(len + 1);
		if (new[a] == NULL)
			return (NULL);
		len += i;
		for (int j = 0; i < len && str[i] != '\0'; i++)
			new[a][j++] = str[i];
		new[a] = clear_str(new[a]);
		if (str[i] != '\0' && str[i] == '|' )
			i += 2;
	}
	new[count] = NULL;
	return (new);
}

char **split_line_separator(char *str)
{
	char **arr = NULL;
	int count = 1;

	if (str == NULL)
		return (NULL);
	count = str_to_array_count_words(str, count);
	arr = get_the_array(str, count);
	if (arr == NULL)
		return (NULL);
	return (arr);
}
