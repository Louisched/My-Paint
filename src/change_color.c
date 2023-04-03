/*
** EPITECH PROJECT, 2023
** B-MUL-200-MLN-2-1-mypaint-louis.chedru
** File description:
** change_color
*/

#include "src.h"
#include <SFML/Graphics.h>

void chcolor_black(elements_t *el)
{
    el->user->brush_color = sfBlack;
}

void chcolor_red(elements_t *el)
{
    el->user->brush_color = sfRed;
}

void chcolor_blue(elements_t *el)
{
    el->user->brush_color = sfBlue;
}

void chcolor_green(elements_t *el)
{
    el->user->brush_color = sfGreen;
}
