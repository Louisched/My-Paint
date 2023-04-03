/*
** EPITECH PROJECT, 2023
** B-MUL-200-MLN-2-1-mypaint-louis.chedru
** File description:
** open_file
*/

#include "src.h"
#include "my.h"
#include <stdlib.h>

sfUint8 *copy_pixels(const sfUint8 *ptr, sfVector2u size)
{
    int mem = size.x * size.y * 4;
    sfUint8 *new_ptr = malloc(sizeof(sfUint8) * mem);
    for (int i = 0 ; i < mem ; i++) {
        new_ptr[i] = ptr[i];
    }
    mini_printf("size: %i\n", size);
    return new_ptr;
}

int menu_open_file(elements_t *el, char *name)
{
    sfImage *img = sfImage_createFromFile(name);
    if (!img) return -1;
    sfVector2u img_size = sfImage_getSize(img);
    el->drarea->drawing = copy_pixels(sfImage_getPixelsPtr(img), img_size);
    sfVector2f rect_size;
    rect_size.x = img_size.x, rect_size.y = img_size.y;
    sfRectangleShape_setSize(el->drarea->area, rect_size);
    sfVector2f dr_pos;
    sfVector2u win_size = sfRenderWindow_getSize(el->window);
    dr_pos.x = (win_size.x / 2) - (rect_size.x / 2);
    dr_pos.y = (win_size.y / 2) - (rect_size.y / 2);
    sfRectangleShape_setPosition(el->drarea->area, dr_pos);
    el->drarea->pos.x = (int)dr_pos.x;
    el->drarea->pos.y = (int)dr_pos.y;
    sfSprite_destroy(el->drarea->sprite);
    el->drarea->sprite = sfSprite_create();
    sfSprite_setPosition(el->drarea->sprite, dr_pos);
    sfTexture_destroy(el->drarea->texture);
    el->drarea->texture = sfTexture_create(rect_size.x, rect_size.y);
    sfSprite_setTexture(el->drarea->sprite, el->drarea->texture, sfTrue);
}

void open_win_handle_keys(sfEvent event, struct params *params)
{
    if (event.key.code == sfKeyEnter) {
        params->buff[params->i] = '\0';
        int ret = menu_open_file(params->el, params->buff);
        if (ret == -1) {
            sfRenderWindow_close(params->win);
            return open_file_win(params->el);
        }
        sfRenderWindow_close(params->win);
    }
    if (event.key.code == sfKeyEscape)
        sfRenderWindow_close(params->win);
}

void open_win_event(struct params *params)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(params->win, &event)) {
        if (event.type == sfEvtKeyPressed)
            open_win_handle_keys(event, params);
        if (event.type == sfEvtTextEntered)
            write_user_input(event, params);
    }
}

void open_file_win(elements_t *el)
{
    struct params *params = init_save_params(el, "Open");
    sfText *text = sfText_create();
    sfText_setFont(text, el->font);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, "Enter file name with extesion (png, jpg etc.)");
    while (sfRenderWindow_isOpen(params->win)) {
        open_win_event(params);
        sfRenderWindow_clear(params->win, sfWhite);
        sfRenderWindow_drawText(params->win, params->input, NULL);
        sfRenderWindow_drawText(params->win, text, NULL);
        sfRenderWindow_display(params->win);
    }
    sfText_destroy(params->input);
    sfRenderWindow_destroy(params->win);
}
