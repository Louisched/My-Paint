/*
** EPITECH PROJECT, 2023
** side_menu_button.c
** File description:
** all the button other then the menu
*/

#include "src.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>

void destroy_button(button_t *button)
{
    sfRectangleShape_destroy(button->shape);
    sfText_destroy(button->text);
}

void draw_button(sfRenderWindow *window, button_t *button)
{
    sfRectangleShape_setFillColor(button->shape, button->color);
    sfRenderWindow_drawRectangleShape(window, button->shape, NULL);
    sfRenderWindow_drawText(window, button->text, NULL);
}

button_t *create_button(sfVector2f position, const char *button_text,
void (* func)(elements_t *))
{
    button_t *button = malloc(sizeof(button_t));
    button->shape = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->shape, position);
    sfRectangleShape_setSize(button->shape, (sfVector2f){200, 50});
    sfRectangleShape_setFillColor(button->shape, sfColor_fromRGB(255, 128, 0));
    sfRectangleShape_setOutlineColor(button->shape, sfWhite);
    sfRectangleShape_setOutlineThickness(button->shape, 2.0f);
    sfVector2f text_position = { position.x + 50.0f, position.y + 10.0f };
    button->text = sfText_create();
    sfText_setFont(button->text, sfFont_createFromFile("assets/ARIAL.TTF"));
    sfText_setCharacterSize(button->text, 24);
    sfText_setString(button->text, button_text);
    sfText_setPosition(button->text, text_position);
    sfText_setFillColor(button->text, sfWhite);
    button->color = sfColor_fromRGB(255, 128, 0);
    button->func = func;
    return (button);
}

void handle_button_event(elements_t *el, button_t *button, bool click)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(el->window);
    sfFloatRect button_bounds = sfRectangleShape_getGlobalBounds(button->shape);
    if (sfFloatRect_contains(&button_bounds, mouse_pos.x, mouse_pos.y)) {
        button->color = sfColor_fromRGB(128, 255, 0);
        if (click) button->func(el);
    } else {
        button->color = sfColor_fromRGB(255, 128, 0);
    }
}

void button_click_state(elements_t *el)
{
    for (int i = 0 ; el->buttons[i] ; i++) {
        button_t *b = el->buttons[i];
        sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(el->window);
        sfFloatRect button_bounds = sfRectangleShape_getGlobalBounds(b->shape);
        if (sfFloatRect_contains(&button_bounds, mouse_pos.x, mouse_pos.y)) {
            b->color = sfColor_fromRGB(0, 0, 110);
        } else {
            b->color = sfColor_fromRGB(255, 128, 0);
        }
    }
}
