/*
** EPITECH PROJECT, 2023
** B-MUL-200-MLN-2-1-mypaint-louis.chedru
** File description:
** menu_btn
*/

#include "my.h"
#include "src.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

menu_button_t *menu_btn_init(char *text, void (* func)(elements_t *), int ind,
menu_t *menu)
{
    const sfFont *font = sfText_getFont(menu->text);
    menu_button_t *btn = malloc(sizeof(menu_button_t));
    btn->func = func;
    btn->rect = sfRectangleShape_create();
    sfVector2f size = sfRectangleShape_getSize(menu->rect);
    sfVector2f pos = sfRectangleShape_getPosition(menu->rect);
    size.x *= 2;
    pos.y += size.y + ind * size.y;
    sfRectangleShape_setOutlineColor(btn->rect, sfBlack);
    sfRectangleShape_setFillColor(btn->rect, sfWhite);
    sfRectangleShape_setOutlineThickness(btn->rect, 2.0);
    sfRectangleShape_setSize(btn->rect, size);
    sfRectangleShape_setPosition(btn->rect, pos);
    btn->text = sfText_create();
    sfText_setString(btn->text, text);
    sfText_setFont(btn->text, font);
    sfText_setPosition(btn->text, pos);
    sfText_setColor(btn->text, sfBlack);
    return btn;
}

void do_btn_click(menu_button_t *btn, elements_t *el)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(el->window);
    sfVector2f btn_pos = sfRectangleShape_getPosition(btn->rect);
    sfVector2f btn_size = sfRectangleShape_getSize(btn->rect);
    if (mouse_pos.x >= btn_pos.x
    && mouse_pos.x <= btn_pos.x + btn_size.x
    && mouse_pos.y >= btn_pos.y
    && mouse_pos.y <= btn_pos.y + btn_size.y)
        btn->func(el);
}

void menu_btn_click(elements_t *el)
{
    for (int i = 0 ; el->menu_bar->menus[i] ; i++) {
        menu_t *menu = el->menu_bar->menus[i];
        for (int j = 0 ; menu->is_clicked && menu->butts[j] ; j++)
            do_btn_click(menu->butts[j], el);
    }
}
