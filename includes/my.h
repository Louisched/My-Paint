/*
** EPITECH PROJECT, 2022
** My
** File description:
** My header
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdbool.h>

int my_putstr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_strlen(char *str);
bool my_strcmp(char *s1, char *s2);
int mini_printf(const char *format, ...);
void my_strcpy(char *, char *);

    #define debug my_putstr("debug\n");
    #define BSN my_putchar('\n')

#endif /* !MY_H_ */
