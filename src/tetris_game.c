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

void Core_display(arguments_t *arguments, tetri_t *tetrimino, int size[2])
{
    arguments->frame += 1;
    /*Display_drawRect(&((t_vect){(size[0] / 2) - core->size.x - 2,
                (size[1] / 2) - (arguments->map_size_y  / 2) - 1}),
            &((t_vect){core->size.x + 2, arguments->map_size_y  + 2}), 7);
    if (core->next && next) {
        Display_drawAt(next, &((t_vect){(size[0] / 2) + arguments->map_size_x + 8,
                    (size[1] / 2) - 5}));
        Display_drawRect(&((t_vect){(size[0] / 2) + arguments->map_size_x + 4,
                    (size[1] / 2) - 7}),
            &((t_vect){next->size[0].x + 4, next->size[0].y + 4}), 7);
        attron(COLOR_PAIR(color));
        mvprintw((size[1] / 2) - 7, (size[0] / 2) + core->size.x + 6, "NEXT");
    }*/
    Display_stats(arguments, arguments->score / 1000 + arguments->level);
    Display_title();
    Display_drawMap(arguments, size);
    /*if (actual)
        Display_draw(actual, &(core->size), size);*/
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
    /*if (size[0] <= arguments->map_size_y || size[1] <= arguments->map_size_x)
        return (84);*/
    //loose = Core_handleActual(arguments, actual, next, size, level);
    //Core_handleScore(arguments);
    level = (arguments->score / 1000) + arguments->level;
    Core_display(arguments, tetrimino, size);
    refresh();
    if (loose == 1) {
        //set_read_mode(0);
        return (1);
    }
    usleep(20000);
    return (0);
}

void tetris_start(arguments_t *arguments, tetri_t *tetrimino)
{
    while (loop_game(arguments, tetrimino) == 0);
}