/*
** EPITECH PROJECT, 2017
** header
** File description:
** lib
*/

#ifndef MY_H
#define MY_H

void my_putchar(char c);
int my_put_nbr(int nb);
int my_strlen(char *str);
int my_getnbr(char *str);
char **my_str_to_word_array(char const *str, char);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strcmp(char *s1, char *s2);
char *my_strcat_malloc(char *dest, char *src);
int my_array_size(char **);
int my_putstr(char *str);
void my_memset(char *, int);
char *clear_str(char *, char);
int my_str_isalpha(char *);

#endif
