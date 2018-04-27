/*
** EPITECH PROJECT, 2017
** functions2.c
** File description:
** Made by developers
*/

#include "minishell.h"

char		**my_copy_env(char **env, int extension)
{
	int	i = -1;
	int	a = -1;
	char	**tab = malloc(sizeof(char*)
		* (my_size_tab(env) + extension + 1));

	while (env[++i])
		tab[i] = env[i];
	while (++a < extension)
		tab[i++] = NULL;
	tab[i] = NULL;
	return (tab);
}

int		my_set_env(t_mini *control, char *key, char *value)
{
	int	i = -1;

	if (!my_str_alpha(key)) {
		my_putstr("setenv: Variable name must", 1);
		my_putstr(" contain alphanumeric characters.\n", 1);
		control->status = 1;
		return (0);
	}
	if (my_get_env(*control, key) == NULL) {
		control->env = my_copy_env(control->env, 1);
		while (control->env[++i]);
		control->env[i] = my_strcat(key, my_strcat("=", value, 0), 0);
	} else {
		while (control->env[++i])
			if (my_str_start(control->env[i],
				my_strcat(key, "=", 0)))
				control->env[i] = my_strcat(key,
				my_strcat("=", value, 0), 0);
	}
	return (1);
}

void		my_unset_env(t_mini *control, char *key)
{
	int	i = -1;
	int	a = 0;
	char	**env = malloc(sizeof(char*) * (my_size_tab(control->env) + 1));

	while (control->env[++i])
		if (my_str_start(control->env[i], my_strcat(key, "=", 0)))
			control->env[i] = "removed";
	i = -1;
	while (control->env[++i])
		if (my_str_start(control->env[i], "removed") == 0)
			env[a++] = control->env[i];
	env[a] = NULL;
	control->env = env;
}

char		*my_get_env(t_mini control, char const *key)
{
	int	i = -1;
	int	j = 0;
	int	a = 0;
	char	*result;

	while (control.env[++i]) {
		if (my_str_start(control.env[i], my_strcat(key, "=", 0))) {
			result = malloc(my_strlen(control.env[i]) + 1);
			j += my_strlen(key);
			while (control.env[i][++j])
				result[a++] = control.env[i][j];
			result[a] = 0;
			return (result);
		}
	}
	return (NULL);
}
