/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** Main file for Tetris' bootstrap
*/

#include <stdlib.h>
#include <stdio.h>
#include "libmy.h"
#include "tetris.h"

int start_program(arguments_t *arguments, tetri_t *tetrimino)
{
    if (arguments->debug == 1)
        tetris_debug(arguments, tetrimino);
    tetris_start(arguments);
    return (0);
}

int main(int ac, char **av)
{
    tetri_t *tetrimino;
    arguments_t *arguments = NULL;
    int nbr_tets = 0;

    if (ac > 1)
        if (my_strcmp(av[1], "--help") == 0 || my_strcmp(av[1], "-h") == 0)
            return (print_help());
    arguments = arguments_tetris(ac, av, arguments);
    tetrimino = check_folder(arguments, nbr_tets);
    arguments->nbr_tets = share_nbr_tetris(0);
    start_program(arguments, tetrimino);
    if (tetrimino == NULL)
        return (84);
    return (0);
}