/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "my.h"
#include "src.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void handle_keys(elements_t *el)
{
    if (el->event.key.code == sfKeyE) el->user->brush = brush_earaser;
        if (el->event.key.code == sfKeyP)
            el->user->brush = brush_pencil;
        if (el->event.key.code == sfKeyEscape)
            sfRenderWindow_close(el->window);
}

void analyse_events(elements_t *el)
{
    while (sfRenderWindow_pollEvent(el->window, &el->event)) {
        if (el->event.type == sfEvtClosed)
            sfRenderWindow_close(el->window);
        chage_menus_state_over(el);
        buttons_over(el, false);
        if (el->event.type == sfEvtMouseButtonReleased) {
            el->is_clicking = false;
        }
        if (el->event.type == sfEvtMouseButtonPressed) {
            el->is_clicking = true;
            chaange_menu_state_clicked(el);
            menu_btn_click(el);
            menu_clicked(el);
            buttons_over(el, true);
            button_click_state(el);
        }
        if (el->event.type == sfEvtKeyPressed) handle_keys(el);
    }
}

void display(elements_t *el)
{
    sfRenderWindow_clear(el->window, el->bg);
    sfRenderWindow_drawSprite(el->window, el->drarea->sprite, NULL);
    menu_bar_dispplay(el);
    display_buttons(el);
    sfRenderWindow_display(el->window);
}

void destroy(elements_t *el)
{
    sfRenderWindow_destroy(el->window);
}

int main(int argc, char ** argv, char **env)
{
    if (argc == 2 && (argv[1][0] == '-' && argv[1][1] == 'h'))
        return (helping_rules());
    elements_t *el = init();
    el->env = env;
    drarea_t *dr = el->drarea;
    while (sfRenderWindow_isOpen(el->window)) {
        analyse_events(el);
        if (el->is_clicking) el->user->brush(el);
        sfVector2f ds = sfRectangleShape_getSize(el->drarea->area);
        sfTexture_updateFromPixels(dr->texture, dr->drawing, ds.x, ds.y, 0, 0);
        display(el);
    }
    destroy(el);
    return (0);
}
