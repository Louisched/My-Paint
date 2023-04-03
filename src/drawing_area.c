/*
** EPITECH PROJECT, 2023
** B-MUL-200-MLN-2-1-mypaint-louis.chedru
** File description:
** drawing_area
*/

#include "my.h"
#include "src.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>

void drarea_put_pixel(elements_t *el, int x, int y, sfColor color)
{
    drarea_t *drarea = el->drarea;
    sfVector2f vec = sfRectangleShape_getSize(drarea->area);
    if (x >= vec.x || y >= vec.y) return;
    if (x < 0 || y < 0) return;
    int index = (x + y * vec.x) * 4;
    drarea->drawing[index] = color.r;
    drarea->drawing[index + 1] = color.g;
    drarea->drawing[index + 2] = color.b;
    drarea->drawing[index + 3] = color.a;
}

void drarea_fill(drarea_t *drarea)
{
    sfVector2f vec = sfRectangleShape_getSize(drarea->area);
    for (int i = 0 ; i < vec.x * vec.y * 4 ; i++) {
        drarea->drawing[i] = (sfUint8)255;
    }
}

drarea_t *drarea_init(int h, int w, int fd)
{
    drarea_t *drarea = malloc(sizeof(drarea_t));
    drarea->area = sfRectangleShape_create();
    sfVector2f size;
    size.x = w;
    size.y = h;
    sfRectangleShape_setSize(drarea->area, size);
    drarea->texture = sfTexture_create(500, 500);
    drarea->sprite = sfSprite_create();
    sfSprite_setTexture(drarea->sprite, drarea->texture, sfTrue);
    drarea->drawing = malloc((sizeof(sfUint8) * h * w) * 4);
    if (fd == -1) drarea_fill(drarea);
    return drarea;
}

sfVector2f drarea_get_click_coordinates(elements_t *el)
{
    sfVector2f res;
    sfVector2f area_pos = sfRectangleShape_getPosition(el->drarea->area);
    sfVector2f area_size = sfRectangleShape_getSize(el->drarea->area);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(el->window);
    if (mouse_pos.x >= area_pos.x && mouse_pos.x <= area_pos.x + area_size.x
    && mouse_pos.y >= area_pos.y && mouse_pos.y <= area_pos.y + area_size.y) {
        res.x = mouse_pos.x - area_pos.x;
        res.y = mouse_pos.y - area_pos.y;
    } else {
        res.x = -1;
        res.y = -1;
    }
    return res;
}
