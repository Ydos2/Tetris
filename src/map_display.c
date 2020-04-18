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
    attroff(stdscr);
    for (int a = 0; a <= arguments->map_size_y + 1; a++)
        mvprintw((a + 12), 43, "%s\n", arguments->map[a]);
}