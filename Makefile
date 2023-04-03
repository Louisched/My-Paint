##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME = my_paint

SRC	=	main.c \
		my/my_strlen.c \
		my/my_putchar.c \
		my/my_putstr.c \
		my/my_put_nbr.c \
		my/my_strcmp.c \
		my/my_strcpy.c \
		my/mini_printf.c \
		src/init_paint.c \
		src/drawing_area.c \
		src/drawing_shapes.c \
		src/brushes.c \
		src/saving.c \
		src/help.c \
		src/menu_bar.c \
		src/menu_btn.c \
		src/change_tool.c \
		src/menus.c \
		src/save_window_init_params.c \
		src/new_file.c \
		src/open_file.c \
		src/change_state.c \
		src/tools_modify.c \
		src/side_menu_button.c \
		src/init_button.c \
		src/change_color.c

OBJ = $(SRC:.c=.o)

CC = gcc

INCLUDES = -I./includes

LIBS = -lcsfml-graphics -lm

CFLAGS	=	-W $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIBS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
