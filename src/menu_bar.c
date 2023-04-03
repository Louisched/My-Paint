/*
** EPITECH PROJECT, 2023
** B-MUL-200-MLN-2-1-mypaint-louis.chedru
** File description:
** menu_bar
*/

#include "my.h"
#include "src.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void menu_clicked(elements_t *el)
{
    menu_t **menu_array = el->menu_bar->menus;
    for (int i = 0 ; menu_array[i] ; i++) {
        menu_t *menu = menu_array[i];
        sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(el->window);
        sfVector2f menu_pos = sfRectangleShape_getPosition(menu->rect);
        sfVector2f menu_size = sfRectangleShape_getSize(menu->rect);
        if (mouse_pos.x >= menu_pos.x
        && mouse_pos.x <= menu_pos.x + menu_size.x
        && mouse_pos.y >= menu_pos.y
        && mouse_pos.y <= menu_pos.y + menu_size.y)
            menu->is_clicked = true;
        else
            menu->is_clicked = false;
    }
}

menu_t *menu_init(sfVector2f mb_size, int ind, char *text, sfFont *font)
{
    menu_t *menu = malloc(sizeof(menu_t));
    menu->rect = sfRectangleShape_create();
    sfVector2f size;
    size.x = mb_size.x / 10;
    size.y = mb_size.y;
    sfVector2f pos;
    pos.x = size.x * ind;
    pos.y = 0;
    sfRectangleShape_setSize(menu->rect, size);
    sfRectangleShape_setPosition(menu->rect, pos);
    sfRectangleShape_setOutlineColor(menu->rect, sfBlack);
    sfRectangleShape_setOutlineThickness(menu->rect, 2.0);
    menu->text = sfText_create();
    sfText_setString(menu->text, text);
    sfText_setColor(menu->text, sfBlack);
    sfText_setFont(menu->text, font);
    sfText_setPosition(menu->text, pos);
    menu->is_clicked = false;
    return menu;
}

void menu_display_btns(menu_t *menu, elements_t *el)
{
    for (int i = 0 ; menu->butts[i] ; i++) {
        menu_button_t *btn = menu->butts[i];
        sfRenderWindow_drawRectangleShape(el->window, btn->rect, NULL);
        sfRenderWindow_drawText(el->window, btn->text, NULL);
    }
}

void menu_bar_dispplay(elements_t *el)
{
    menu_bar_t *menu_bar = el->menu_bar;
    sfRenderWindow_drawRectangleShape(el->window, menu_bar->rect, NULL);
    for (int i = 0 ; menu_bar->menus[i] ; i++) {
        menu_t *menu = menu_bar->menus[i];
        sfRenderWindow_drawRectangleShape(el->window, menu->rect, NULL);
        sfRenderWindow_drawText(el->window, menu->text, NULL);
        if (menu->is_clicked) menu_display_btns(menu, el);
    }
}
