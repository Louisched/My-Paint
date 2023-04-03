/*
** EPITECH PROJECT, 2023
** B-MUL-200-MLN-2-1-mypaint-louis.chedru
** File description:
** save_window_init_params
*/

#include "src.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

struct params *init_save_params(elements_t *el, char *name)
{
    sfVideoMode mode = {700, 500, 32};
    struct params *params = malloc(sizeof(struct params));
    for (int i = 0 ; i < 128 ; i++) params->buff[i] = '\0';
    params->el = el;
    params->i = 0;
    params->input = sfText_create();
    params->win = sfRenderWindow_create(mode, name, PARAM, NULL);
    sfText_setFont(params->input, el->font);
    sfText_setColor(params->input, sfBlack);
    sfVector2f pos;
    pos.x = 0;
    pos.y = 100;
    sfText_setPosition(params->input, pos);
    return params;
}
