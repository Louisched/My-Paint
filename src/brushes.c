/*
** EPITECH PROJECT, 2023
** B-MUL-200-MLN-2-1-mypaint-louis.chedru
** File description:
** brushes
*/

#include "my.h"
#include "src.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>

void brush_pencil(elements_t *el)
{
    sfVector2f coor = drarea_get_click_coordinates(el);
    if (coor.x == -1 && coor.y == -1) return;
    el->user->brush_shape(el, coor, el->user->brush_color);
}

void brush_earaser(elements_t *el)
{
    sfVector2f coor = drarea_get_click_coordinates(el);
    if (coor.x == -1 && coor.y == -1) return;
    el->user->brush_shape(el, coor, sfWhite);
}
