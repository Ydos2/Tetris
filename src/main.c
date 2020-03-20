/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** Main file for Tetris' bootstrap
*/

#include <stdlib.h>
#include "libmy.h"
#include "tetris.h"

int start_program(arguments_t *arguments, tetri_t tetrimino)
{
    (void)tetrimino;
    if (arguments->debug == 1)
        tetris_debug(arguments);
    tetris_start(arguments);
    return (0);
}

int main(int ac, char **av)
{
    tetri_t tetrimino;
    arguments_t *arguments = NULL;

    tetrimino = check_errors(ac, av, tetrimino);
    if (ac > 1)
        if (my_strcmp(av[1], "--help") == 0) {
        draw_help();
        return (0);
    }
    arguments = arguments_tetris(ac, av, arguments);
    start_program(arguments, tetrimino);
    if (tetrimino.error == 84)
        return (84);
    return (0);
}