/*
** EPITECH PROJECT, 2020
** initialise
** File description:
** initialise
*/

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
}