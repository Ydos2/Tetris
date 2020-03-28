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