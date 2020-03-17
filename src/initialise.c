/*
** EPITECH PROJECT, 2020
** initialise
** File description:
** initialise
*/

#include "bstetris.h"
#include "libmy.h"

void initialise_arguments(arguments_t *arguments)
{
    arguments->key_left = 68;
    arguments->key_right = 67;
    arguments->key_turn = 65;
    arguments->key_drop = 66;
    arguments->key_quit = 'q';
    arguments->key_pause = 32;
    arguments->debug = 0;
    arguments->Level = 1;
    arguments->map_size_x = 10;
    arguments->map_size_y = 20;
    arguments->without_next = 1;
}