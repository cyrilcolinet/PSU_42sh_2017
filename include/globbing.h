/*
** EPITECH PROJECT, 2018
** 42
** File description:
** globbing header
*/

#ifndef PSU_42SH_2017_GLOBBING_H
#define PSU_42SH_2017_GLOBBING_H

#include <glob.h>

#define FLAG_START '-'

char	is_globbing(char *);
glob_t	get_globbing(char *);
int	globbing_in_cmd(char *);

#endif //PSU_42SH_2017_GLOBBING_H
