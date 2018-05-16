/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** Made by developers
*/

#ifndef MY_H
#define MY_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		my_strlen(char const *);
int		my_size_tab(char **);
int		my_free_tab(char **);
void		my_putchar(char, int);
void		my_putstr(char const *, int);
char		*my_strcpy(char *);
char		*get_next_line(int);

#endif
