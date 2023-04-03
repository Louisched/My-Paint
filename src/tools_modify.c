/*
** EPITECH PROJECT, 2023
** B-MUL-200-MLN-2-1-mypaint-louis.chedru
** File description:
** tools_modify
*/

#include "src.h"
#include <SFML/Graphics.h>

void size_plus(elements_t *el)
{
    if (el->user->brush_size == 50) return;
    el->user->brush_size += 5;
}

void size_minus(elements_t *el)
{
    if (el->user->brush_size == 5) return;
    el->user->brush_size -= 5;
}

void chbrush_pacman(elements_t *el)
{
    el->user->brush_shape = draw_pacman;
}

void chbrush_square(elements_t *el)
{
    el->user->brush_shape = draw_square;
}
