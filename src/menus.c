/*
** EPITECH PROJECT, 2023
** B-MUL-200-MLN-2-1-mypaint-louis.chedru
** File description:
** menus
*/

#include "my.h"
#include "src.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void menu_btn_init_file(menu_t *menu)
{
    menu->butts = malloc(sizeof(menu_button_t *) * 4);
    menu->butts[0] = menu_btn_init("Save", save_window, 0, menu);
    menu->butts[1] = menu_btn_init("New file", new_file, 1, menu);
    menu->butts[2] = menu_btn_init("Open file", open_file_win, 2, menu);
    menu->butts[3] = NULL;
}

void menu_btn_init_edit(menu_t *menu)
{
    menu->butts = malloc(sizeof(menu_button_t *) * 7);
    menu->butts[0] = menu_btn_init("Pencil", set_pencil, 0, menu);
    menu->butts[1] = menu_btn_init("Eraser", set_eraser, 1, menu);
    menu->butts[2] = menu_btn_init("Size +", size_plus, 2, menu);
    menu->butts[3] = menu_btn_init("Size -", size_minus, 3, menu);
    menu->butts[4] = menu_btn_init("Pacman shape", chbrush_pacman, 4, menu);
    menu->butts[5] = menu_btn_init("Square shape", chbrush_square, 5, menu);
    menu->butts[6] = NULL;
}

void menu_btn_init_help(menu_t *menu)
{
    menu->butts = malloc(sizeof(menu_button_t *) * 3);
    menu->butts[0] = menu_btn_init("About", about, 0, menu);
    menu->butts[1] = menu_btn_init("Help", help, 1, menu);
    menu->butts[2] = NULL;
}
