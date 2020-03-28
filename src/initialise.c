/*
** EPITECH PROJECT, 2020
** initialise
** File description:
** initialise
*/

#include <ncurses.h>
#include "tetris.h"
#include "libmy.h"

int share_nbr_tetris(int entry)
{
    static int stocked_nbr = 0;

    if (entry == 0)
        return (stocked_nbr);
    else
        stocked_nbr = entry;
    return (0);
}

void initialise_arguments(arguments_t *arguments)
{
    arguments->key_left = 68;
    arguments->key_right = 67;
    arguments->key_turn = 65;
    arguments->key_drop = 66;
    arguments->key_quit = 'q';
    arguments->key_pause = 32;
    arguments->debug = 0;
    arguments->level = 1;
    arguments->map_size_x = 10;
    arguments->map_size_y = 20;
    arguments->without_next = 1;
    arguments->nbr_tets = 0;
    arguments->score = 0;
    arguments->frame = 0;
    arguments->start_time = 0;
    arguments->high_score = 0;
}

void initialise_ncurse(arguments_t *arguments)
{
    int	index[2];

    initscr();
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(3, COLOR_WHITE, COLOR_RED);
    init_pair(4, COLOR_WHITE, COLOR_GREEN);
    init_pair(5, COLOR_WHITE, COLOR_CYAN);
    init_pair(6, COLOR_WHITE, COLOR_YELLOW);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    init_pair(8, COLOR_BLACK, COLOR_WHITE);
    index[0] = ((arguments->map = xmalloc(sizeof(char *) * arguments->map_size_y)) == 0) - 1;
    while (++index[0] < arguments->map_size_y) {
        index[1] = -1;
        arguments->map[index[0]] = xmalloc(sizeof(char) * (arguments->map_size_x + 1));
        while (++index[1] < arguments->map_size_x)
            arguments->map[index[0]][index[1]] = 0;
    }
}