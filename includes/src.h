/*
** EPITECH PROJECT, 2022
** functions
** File description:
** functions
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

#ifndef FUNCTIONS_H_
    #define FUNCTIONS_H_

    #define PARAM sfClose | sfResize

    typedef struct drawing_area {
        sfRectangleShape *area;
        sfUint8 *drawing;
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2i pos;
    } drarea_t;

    typedef struct elements elements_t;

    typedef struct user_data {
        void (* brush)(elements_t *);
        void (* brush_shape)(elements_t *, sfVector2f, sfColor);
        sfColor brush_color;
        int brush_size;
    } udata_t;

    typedef struct menu_button {
        sfRectangleShape *rect;
        sfText *text;
        void (* func)(elements_t *);
    } menu_button_t;

    typedef struct menu {
        sfRectangleShape *rect;
        sfText *text;
        menu_button_t **butts;
        bool is_clicked;
    } menu_t;

    typedef struct menu_bar {
        sfRectangleShape *rect;
        menu_t **menus;
    } menu_bar_t;

    typedef struct button {
        sfRectangleShape* shape;
        sfText* text;
        sfColor color;
        void (* func)(elements_t *);
    } button_t;

    struct elements {
        sfRenderWindow *window;
        sfEvent event;
        drarea_t *drarea;
        bool is_clicking;
        sfColor bg;
        udata_t *user;
        menu_bar_t *menu_bar;
        sfFont *font;
        char **env;
        button_t **buttons;
    };

    typedef struct {
        sfVector2f size;
        sfUint8 *tab;
    } ffile_info_t;

    /* Structure for saving window elements */
    struct params {
        int i;
        sfText *input;
        elements_t *el;
        char buff[128];
        sfRenderWindow *win;
    };

    typedef enum {NONE, OVER, CLICKED} state_t;

    elements_t *init(void);
    drarea_t *drarea_init(int h, int w, int fd);
    void drarea_put_pixel(elements_t *el, int x, int y, sfColor color);
    sfVector2f drarea_get_click_coordinates(elements_t *el);
    char **my_str_to_word_array(char const *str);
    int my_getnbr(char *str);
    void save(elements_t *el, char *name);
    int helping_rules(void);
    void menu_bar_dispplay(elements_t *el);
    menu_t *menu_init(sfVector2f mb_size, int ind, char *text, sfFont *font);
    menu_bar_t *menu_bar_init(sfVector2f win_size, sfFont *font);
    void menu_clicked(elements_t *el);
    menu_button_t *menu_btn_init(char *text, void (* func)(elements_t *),
    int ind, menu_t *menu);
    void menu_btn_init_file(menu_t *menu);
    void menu_btn_click(elements_t *el);
    void menu_btn_init_edit(menu_t *menu);
    void help(elements_t *el);
    void about(elements_t *el);
    void menu_btn_init_help(menu_t *menu);
    void save_window(elements_t *el);
    struct params *init_save_params(elements_t *el, char *name);
    void modify_drarea(elements_t *el);
    void new_file(elements_t *el);
    void write_user_input(sfEvent event, struct params *params);
    void open_file_win(elements_t *el);
    void chage_menus_state_over(elements_t *el);
    void chaange_menu_state_clicked(elements_t *el);
    void drarea_fill(drarea_t *drarea);
    void size_plus(elements_t *el);
    void size_minus(elements_t *el);
    void chbrush_pacman(elements_t *el);
    void chbrush_square(elements_t *el);
    void buttons_over(elements_t *el, bool click);
    button_t *create_button(sfVector2f position, const char *button_text,
    void (* func)(elements_t *));
    button_t **init_buttons(elements_t *el);
    void handle_button_event(elements_t *el, button_t *button, bool click);
    void display_buttons(elements_t *el);
    void draw_button(sfRenderWindow *window, button_t *button);
    void button_click_state(elements_t *el);

    /* Change tool */
    void set_pencil(elements_t *el);
    void set_eraser(elements_t *el);

    /* Brushes */
    void brush_pencil(elements_t *el);
    void brush_earaser(elements_t *el);

    /* Shapes */
    void draw_pacman(elements_t *el, sfVector2f coor, sfColor color);
    void draw_square(elements_t *el, sfVector2f coor, sfColor color);

    /* Colors */
    void chcolor_black(elements_t *el);
    void chcolor_red(elements_t *el);
    void chcolor_blue(elements_t *el);
    void chcolor_green(elements_t *el);

#endif /* !FUNCTIONS_H_ */
