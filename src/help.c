/*
** EPITECH PROJECT, 2023
** B-MUL-200-MLN-2-1-mypaint-louis.chedru
** File description:
** help
*/

#include "my.h"
#include "src.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>

int helping_rules(void)
{
    my_putstr("Well hello there! Welcome to our own painting application!\n");
    my_putstr("Here is some tips on how to use it :");
    my_putstr("If you want by any chance to leave");
    my_putstr(" the application you can use Echap ");
    my_putstr("or the little cross in the top right of your screen!\n");
    my_putstr("And last but not least: Have fun!\n");
    return 0;
}

void help_events(sfRenderWindow *win)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyEscape)
            sfRenderWindow_close(win);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(win);
        if (event.type = sfEvtClosed)
            sfRenderWindow_close(win);
    }
}

void help(elements_t *el)
{
    sfVideoMode mode = {700, 400, 32};
    sfRenderWindow *win = sfRenderWindow_create(mode, "Help", PARAM, NULL);
    sfText *text = sfText_create();
    sfText_setFont(text, el->font);
    char buff[480];
    for (int i = 0 ; i < 480 ; i++) buff[i] = '\0';
    int fd = open("assets/help.txt", O_RDONLY);
    read(fd, buff, 480);
    sfText_setString(text, buff);
    sfText_setCharacterSize(text, 20);
    sfText_setColor(text, sfBlack);
    while (sfRenderWindow_isOpen(win)) {
        help_events(win);
        sfRenderWindow_clear(win, sfWhite);
        sfRenderWindow_drawText(win, text, NULL);
        sfRenderWindow_display(win);
    }
    sfRenderWindow_destroy(win);
    return;
}

char *get_login(char **env)
{
    char *logname_var = NULL;
    for (int i = 0 ; env[i] ; i++) {
        if (env[i][0] == 'L' && env[i][1] == 'O' && env[i][2] == 'G'
        && env[i][3] == 'N' && env[i][4] == 'A' && env[i][5] == 'M'
        && env[i][6] == 'E' && env[i][7] == '=') {
            logname_var = malloc(my_strlen(env[i]) * sizeof(char));
            my_strcpy(env[i], logname_var);
        }
    }
    if (!logname_var) return "No logname.";
    int size = 1;
    for (; logname_var[size] ; size++);
    char *res = malloc(size * sizeof(char));
    int j = 0;
    for (int i = 8 ; logname_var[i] ; i++, j++) {
        res[j] = logname_var[i];
    }
    res[j] = '\0';
    return res;
}

void about(elements_t *el)
{
    sfVideoMode mode = {700, 400, 32};
    sfRenderWindow *win = sfRenderWindow_create(mode, "Help", PARAM, NULL);
    sfText *text = sfText_create();
    sfText_setFont(text, el->font);
    sfText_setCharacterSize(text, 20);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, get_login(el->env));
    while (sfRenderWindow_isOpen(win)) {
        help_events(win);
        sfRenderWindow_clear(win, sfWhite);
        sfRenderWindow_drawText(win, text, NULL);
        sfRenderWindow_display(win);
    }
    sfRenderWindow_destroy(win);
    return;
}
