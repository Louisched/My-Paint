/*
** EPITECH PROJECT, 2023
** B-MUL-200-MLN-2-1-mypaint-louis.chedru
** File description:
** saving
*/

#include "my.h"
#include "src.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

void save(elements_t *el, char *name)
{
    sfVector2f vec = sfRectangleShape_getSize(el->drarea->area);
    sfVideoMode tmp_mode = {vec.x, vec.y, 32};
    sfRenderWindow *tmp_win;
    tmp_win = sfRenderWindow_create(tmp_mode, "tmp", PARAM, NULL);
    sfSprite *sprite_cpy = sfSprite_copy(el->drarea->sprite);
    sfVector2f cpy_pos;
    cpy_pos.x = 0;
    cpy_pos.y = 0;
    sfSprite_setPosition(sprite_cpy, cpy_pos);
    sfRenderWindow_drawSprite(tmp_win, sprite_cpy, NULL);
    sfImage *capture = sfRenderWindow_capture(tmp_win);
    sfImage_saveToFile(capture, name);
    sfSprite_destroy(sprite_cpy);
    sfImage_destroy(capture);
    sfRenderWindow_destroy(tmp_win);
}

void write_user_input(sfEvent event, struct params *params)
{
    if (event.text.unicode == 8) {
        if (params->i > 0) {
            params->buff[params->i - 1] = '\0';
            params->i--;
        }
    } else if (params->i < 128) {
        params->buff[params->i] = event.text.unicode;
        params->i++;
    }
    sfText_setString(params->input, params->buff);
}

void save_win_handle_keys(sfEvent event, struct params *params)
{
    if (event.key.code == sfKeyEnter) {
        save(params->el, params->buff);
        params->buff[params->i] = '\0';
        sfRenderWindow_close(params->win);
    }
    if (event.key.code == sfKeyEscape)
        sfRenderWindow_close(params->win);
}

void save_win_event(struct params *params)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(params->win, &event)) {
        if (event.type == sfEvtKeyPressed)
            save_win_handle_keys(event, params);
        if (event.type == sfEvtTextEntered)
            write_user_input(event, params);
    }
}

void save_window(elements_t *el)
{
    struct params *params = init_save_params(el, "Save");
    sfText *text = sfText_create();
    sfText_setFont(text, el->font);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, "Enter file name with extesion (png, jpg etc.)");
    while (sfRenderWindow_isOpen(params->win)) {
        save_win_event(params);
        sfRenderWindow_clear(params->win, sfWhite);
        sfRenderWindow_drawText(params->win, params->input, NULL);
        sfRenderWindow_drawText(params->win, text, NULL);
        sfRenderWindow_display(params->win);
    }
    sfText_destroy(params->input);
    sfRenderWindow_destroy(params->win);
}
