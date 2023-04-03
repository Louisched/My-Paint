/*
** EPITECH PROJECT, 2023
** B-MUL-200-MLN-2-1-mypaint-louis.chedru
** File description:
** change_state
*/

#include "src.h"
#include <SFML/Graphics.h>
#include "my.h"

void change_state(sfRectangleShape *rect, sfText *text, state_t state)
{
    if (state == NONE) {
        sfRectangleShape_setFillColor(rect, sfWhite);
        sfText_setColor(text, sfBlack);
        return;
    }
    if (state == OVER) {
        sfRectangleShape_setFillColor(rect, sfBlue);
        sfText_setColor(text, sfWhite);
        return;
    }
    if (state == CLICKED) {
        sfRectangleShape_setFillColor(rect, sfBlack);
        sfText_setColor(text, sfWhite);
        return;
    }
}

void is_over(elements_t *el, sfRectangleShape *rect, sfText *text)
{
    sfVector2f rect_pos = sfRectangleShape_getPosition(rect);
    sfVector2f rect_size = sfRectangleShape_getSize(rect);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(el->window);
    if (mouse_pos.x >= rect_pos.x
    && mouse_pos.x <= rect_pos.x + rect_size.x
    && mouse_pos.y >= rect_pos.y
    && mouse_pos.y <= rect_pos.y + rect_size.y) {
        change_state(rect, text, OVER);
    } else {
        change_state(rect, text, NONE);
    }
}

void is_clicked(elements_t *el, sfRectangleShape *rect, sfText *text)
{
    sfVector2f rect_pos = sfRectangleShape_getPosition(rect);
    sfVector2f rect_size = sfRectangleShape_getSize(rect);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(el->window);
    if (mouse_pos.x >= rect_pos.x
    && mouse_pos.x <= rect_pos.x + rect_size.x
    && mouse_pos.y >= rect_pos.y
    && mouse_pos.y <= rect_pos.y + rect_size.y) {
        change_state(rect, text, CLICKED);
    } else {
        change_state(rect, text, NONE);
    }
}

void chage_menus_state_over(elements_t *el)
{
    for (int i = 0 ; el->menu_bar->menus[i] ; i++) {
        menu_t *menu = el->menu_bar->menus[i];
        is_over(el, menu->rect, menu->text);
        for (int j = 0 ; menu->butts[j] ; j++) {
            is_over(el, menu->butts[j]->rect, menu->butts[j]->text);
        }
    }
}

void chaange_menu_state_clicked(elements_t *el)
{
    for (int i = 0 ; el->menu_bar->menus[i] ; i++) {
        menu_t *menu = el->menu_bar->menus[i];
        is_clicked(el, menu->rect, menu->text);
        for (int j = 0 ; menu->butts[j] ; j++) {
            is_clicked(el, menu->butts[j]->rect, menu->butts[j]->text);
        }
    }
}
