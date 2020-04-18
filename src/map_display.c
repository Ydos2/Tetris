/*
** EPITECH PROJECT, 2020
** map_display
** File description:
** map_display
*/

#include <ncurses.h>
#include "libmy.h"
#include "tetris.h"

void display_map(arguments_t *arguments)
{
    attron(COLOR_PAIR(8));
    for (int a = 0; a != arguments->map_size_y; a++)
        mvprintw(a, 0, arguments->map[a]);
    refresh();
}