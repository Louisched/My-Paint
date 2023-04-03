/*
** EPITECH PROJECT, 2023
** init_button.c
** File description:
** init button
*/

#include "my.h"
#include "src.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void display_buttons(elements_t *el)
{
    for (int i = 0; el->buttons[i]; i++) {
        draw_button(el->window, el->buttons[i]);
    }
}

button_t **init_buttons(elements_t *el)
{
    el->buttons = malloc(sizeof(button_t) * 11);
    sfVector2f  pos1 = {10, 200},    pos2 = {10, 250},    pos3 = {10, 350},
                pos4 = {10, 400},    pos5 = {10, 500},    pos6 = {10, 550},
                pos7 = {10, 650},    pos8 = {10, 700},    pos9 = {10, 750},
                pos10 = {10, 800};
    el->buttons[0] = create_button(pos1, "+", size_plus);
    el->buttons[1] = create_button(pos2, "-", size_minus);
    el->buttons[2] = create_button(pos3, "Pencil", set_pencil);
    el->buttons[3] = create_button(pos4, "Eraser", set_eraser);
    el->buttons[4] = create_button(pos5, "Square", chbrush_square);
    el->buttons[5] = create_button(pos6, "Pacman",chbrush_pacman);
    el->buttons[6] = create_button(pos7, "Black",chcolor_black);
    el->buttons[7] = create_button(pos8, "Red",chcolor_red);
    el->buttons[8] = create_button(pos9, "Blue",chcolor_blue);
    el->buttons[9] = create_button(pos10, "Green",chcolor_green);
    el->buttons[10] = NULL;
}

void buttons_over(elements_t *el, bool click)
{
    for (int i = 0 ; el->buttons[i] ; i++) {
        handle_button_event(el, el->buttons[i], click);
    }
}
