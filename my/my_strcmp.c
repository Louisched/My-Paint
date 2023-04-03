/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** my_strcmp
*/

#include <stdbool.h>
#include <my.h>

bool my_strcmp(char *s1, char *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return (false);
    for (int i = 0 ; s1[i] != '\0' ; i++)
        if (s1[i] != s2[i])
            return (false);
    return (true);
}
