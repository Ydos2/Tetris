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

static int end_move(arguments_t *arguments, tetri_t *tetrimino)
{
    if (arguments->pos_actu_y == arguments->map_size_y - 4) {
        arguments->pos_actu_x = 0;
        arguments->pos_actu_y = 0;
        spawn_tetri(arguments, tetrimino);
        return (1);
    }
    return (0);
}

static void change_map(arguments_t *arguments, tetri_t *tetrimino)
{
    if (end_move(arguments, tetrimino) == 1)
        return;
    arguments->pos_actu_y += 1;
    change_map_tetri(arguments, tetrimino
        [arguments->nbr_rand_tetri].shape);
}

void display(arguments_t *arguments, tetri_t *tetrimino, int size[2])
{
    arguments->frame += 1;
    display_stats(arguments, arguments->score / 1000 + arguments->level);
    display_title();
    if (arguments->pause == 1)
        mvprintw(size[1] / 2, size[0] / 2 - 3, "PAUSED");
    else
        change_map(arguments, tetrimino);
    display_map(arguments);
    refresh();
}

int loop_game(arguments_t *arguments, tetri_t *tetrimino)
{
    int loose = 0;
    int size[2];
    static int level = -1;

    if (level < 0) {
        level = arguments->level;
        spawn_tetri(arguments, tetrimino);
    }
    clear();
    getmaxyx(stdscr, size[1], size[0]);
    level = (arguments->score / 1000) + arguments->level;
    display(arguments, tetrimino, size);
    loose = handle_actual(arguments, size, level);
    if (loose == -1)
        return (1);
    refresh();
    usleep(200000);
    return (0);
}

void tetris_start(arguments_t *arguments, tetri_t *tetrimino)
{
    while (loop_game(arguments, tetrimino) == 0);
    clear();
    getch();
    endwin();
}