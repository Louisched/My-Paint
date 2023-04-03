/*
** EPITECH PROJECT, 2023
** B-MUL-200-MLN-2-1-mypaint-louis.chedru
** File description:
** drawing_shapes
*/

#include "my.h"
#include "src.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>

void draw_pacman(elements_t *el, sfVector2f coor, sfColor color)
{
    drarea_put_pixel(el, coor.x, coor.y, sfBlack);
    int r = el->user->brush_size;
    const double pi = 3.1415926535;
    double i, angle, x1, y1;
    for (int j = r ; j > 0 ; j--) {
        for (i = 0 ; i < 300 ; i++) {
            angle = i;
            x1 = j * cos(angle * pi / 180);
            y1 = j * sin(angle * pi / 180);
            drarea_put_pixel(el, coor.x + x1, coor.y + y1, color);
        }
    }
}

void draw_triangle(elements_t *el, int r, sfVector2f coor)
{
    drarea_put_pixel(el, coor.x, coor.y, sfBlack);
    for (int i = 0 ; i < r ; i++) {
        for (int j = 0 ; j < i / 2 ; j++)
            drarea_put_pixel(el, coor.x + j, coor.y - i, sfBlack);
        for (int k = 0 ; k > (i / 2) * -1 ; k--)
            drarea_put_pixel(el, coor.x + k, coor.y + i, sfBlack);
    }
    for (int i = 0 ; i < i ; i++) {
        for (int j = 0 ; j < i / 2 ; j++)
            drarea_put_pixel(el, coor.x + j, coor.y + i, sfBlack);
        for (int k = 0 ; k > (i / 2) * -1 ; k--)
            drarea_put_pixel(el, coor.x + k, coor.y - i, sfBlack);
    }
}

void draw_square(elements_t *el, sfVector2f coor, sfColor color)
{
    drarea_put_pixel(el, coor.x, coor.y, sfBlack);
    int size = el->user->brush_size / 2;
    for (int i = size * -1 ; i < size ; i++) {
        for (int j = 0 ; j < el->user->brush_size / 2 ; j++) {
            drarea_put_pixel(el, coor.x + i, coor.y + j, color);
        }
        for (int k = 0 ; k > el->user->brush_size / -2 ; k--) {
            drarea_put_pixel(el, coor.x + i, coor.y + k, color);
        }
    }
}
