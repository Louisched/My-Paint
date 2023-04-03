/*
** EPITECH PROJECT, 2023
** B-MUL-200-MLN-2-1-mypaint-louis.chedru
** File description:
** init_paint
*/

#include "my.h"
#include "src.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

udata_t *user_init(void)
{
    udata_t *user = malloc(sizeof(udata_t));
    user->brush = brush_pencil;
    user->brush_shape = draw_square;
    user->brush_color = sfBlack;
    user->brush_size = 20;
    return user;
}

void modify_drarea(elements_t *el)
{
    sfVector2u win_size = sfRenderWindow_getSize(el->window);
    sfVector2f dr_pos;
    sfVector2f rect_size = sfRectangleShape_getSize(el->drarea->area);
    dr_pos.x = (win_size.x / 2) - (rect_size.x / 2);
    dr_pos.y = (win_size.y / 2) - (rect_size.y / 2);
    sfRectangleShape_setPosition(el->drarea->area, dr_pos);
    el->drarea->pos.x = (int)dr_pos.x;
    el->drarea->pos.y = (int)dr_pos.y;
    sfSprite_setPosition(el->drarea->sprite, dr_pos);
    el->bg.r = 0;
    el->bg.g = 180;
    el->bg.b = 180;
    el->bg.a = 255;
    el->user = user_init();
}

menu_bar_t *menu_bar_init(sfVector2f win_size, sfFont *font)
{
    menu_bar_t *menu_bar = malloc(sizeof(menu_bar_t));
    menu_bar->menus = malloc(sizeof(menu_t *) * 4);
    menu_bar->rect = sfRectangleShape_create();
    sfVector2f size;
    size.x = win_size.x;
    size.y = win_size.y / 30;
    sfRectangleShape_setSize (menu_bar->rect, size);
    sfRectangleShape_setFillColor(menu_bar->rect, sfWhite);
    menu_bar->menus[0] = menu_init(size, 0, "File", font);
    menu_bar->menus[1] = menu_init(size, 1, "Edit", font);
    menu_bar->menus[2] = menu_init(size, 2, "Help", font);
    menu_bar->menus[3] = NULL;
    menu_btn_init_file(menu_bar->menus[0]);
    menu_btn_init_edit(menu_bar->menus[1]);
    menu_btn_init_help(menu_bar->menus[2]);
    return menu_bar;
}

elements_t *init(void)
{
    elements_t *el = malloc(sizeof(elements_t));
    sfVideoMode mode = {1920, 1080, 32};
    el->window = sfRenderWindow_create(mode, "My Paint", PARAM, NULL);
    sfRenderWindow_setFramerateLimit(el->window, 60);
    el->drarea = drarea_init(500, 500, -1);
    el->is_clicking = false;
    modify_drarea(el);
    sfVector2f win_size;
    win_size.x = 1920;
    win_size.y = 1080;
    el->font = sfFont_createFromFile("assets/ARIAL.TTF");
    el->menu_bar = menu_bar_init(win_size, el->font);
    init_buttons(el);
    return el;
}
