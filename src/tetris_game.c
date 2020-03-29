/*
** EPITECH PROJECT, 2020
** tetris_game
** File description:
** tetris_game
*/

#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "tetris.h"
#include "libmy.h"

void display(arguments_t *arguments, tetri_t *tetrimino, int size[2])
{
    arguments->frame += 1;
    display_stats(arguments, arguments->score / 1000 + arguments->level);
    display_title();
    display_map(arguments);
}

int loop_game(arguments_t *arguments, tetri_t *tetrimino)
{
    int loose = 0;
    int size[2];
    static int level = -1;

    if (level < 0)
        level = arguments->level;
    clear();
    getmaxyx(stdscr, size[1], size[0]);
    level = (arguments->score / 1000) + arguments->level;
    display(arguments, tetrimino, size);
    refresh();
    loose = handle_actual(arguments, size, level);
    if (loose == -1) {
        clear();
        getch();
        endwin();
        return (1);
    }
    usleep(20000);
    return (0);
}

void tetris_start(arguments_t *arguments, tetri_t *tetrimino)
{
    while (loop_game(arguments, tetrimino) == 0);
}