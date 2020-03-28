/*
** EPITECH PROJECT, 2020
** display
** File description:
** display
*/

#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "tetris.h"
#include "libmy.h"

void Display_animeLost(arguments_t *arguments, int size[2])
{
    int index = -1;

    while (++index < arguments->map_size_y) {
        clear();
        my_memset(arguments->map[index], arguments->map_size_x, 0);
        //Core_display(arguments, NULL, NULL, size);
        refresh();
        usleep(150000);
    }
}

void Display_drawMap(arguments_t *arguments, int size[2])
{
    int index = -1;
    int index2;

    while (++index < arguments->map_size_y) {
        index2 = -1;
        while (++index2 < arguments->map_size_x) {
            attron(COLOR_PAIR(arguments->map[index][index2]));
            mvprintw((size[1] / 2) - (arguments->map_size_y / 2) + index,
                (size[0] / 2) - arguments->map_size_x + (index2 * 2),
                (arguments->map[index][index2]) ? "  " : "");
            attroff(COLOR_PAIR(arguments->map[index][index2]));
        }
    }
}

/*
void Display_drawAt(t_shape *shape, t_vect *pos)
{
    int index;
    int index2;

    attron(COLOR_PAIR(shape->color));
    index = -1;
    while (++index < shape->size[0].y) {
        index2 = -1;
        while (shape->shapes[0][index][++index2]) {
            if (shape->shapes[0][index][index2] == '*')
            mvprintw(pos->y + index, pos->x + (index2 * 2), "  ");
        }
    }
    attroff(COLOR_PAIR(shape->color));
}

void Display_draw(t_shape *shape, t_vect *board, int size[2])
{
    int index;
    int index2;

    attron(COLOR_PAIR(shape->color));
    index = -1;
    while (++index < shape->size[shape->dir].y) {
        index2 = -1;
        while (shape->shapes[shape->dir][index][++index2]) {
            if (shape->shapes[shape->dir][index][index2] == '*' &&
                shape->pos.y + index >= 0)
            mvprintw((size[1] / 2) - (board->y / 2) + shape->pos.y + index,
                    (size[0] / 2) - board->x + ((shape->pos.x + index2) * 2),
                    "  ");
        }
    }
    attroff(COLOR_PAIR(shape->color));
}

void Display_drawRect(t_vect *pos, t_vect *size,
    attribute__((unused))int lol)
{
    int index;
    int index2;

    index = -1;
    attron(COLOR_PAIR(color));
    while (++index < size->y) {
        index2 = -1;
        while (++index2 < size->x) {
            if (index == 0 || index == size->y - 1)
            mvprintw(pos->y + index, pos->x + (index2 * 2), "  ");
            if (index2 == 0 || index2 == size->x - 1)
            mvprintw(pos->y + index, pos->x + (index2 * 2), "  ");
        }
    }
    attroff(COLOR_PAIR(color));
}*/