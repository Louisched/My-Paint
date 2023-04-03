/*
** EPITECH PROJECT, 2023
** B-MUL-200-MLN-2-1-mypaint-louis.chedru
** File description:
** change_tool
*/

#include "my.h"
#include "src.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void set_pencil(elements_t *el)
{
    el->user->brush = brush_pencil;
}

void set_eraser(elements_t *el)
{
    el->user->brush = brush_earaser;
}
